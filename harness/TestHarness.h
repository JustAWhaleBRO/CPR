#ifndef LEETCODECHALLENGES_TESTHARNESS_H
#define LEETCODECHALLENGES_TESTHARNESS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <future>
#include <thread>
#include <type_traits>

// --- Color codes (match Debug.h style) ---
#ifdef NO_COLOR
    #define TH_RESET   ""
    #define TH_CYAN    ""
    #define TH_GREEN   ""
    #define TH_RED     ""
    #define TH_MAGENTA ""
#else
    #define TH_RESET   "\033[0m"
    #define TH_CYAN    "\033[36m"
    #define TH_GREEN   "\033[32m"
    #define TH_RED     "\033[31m"
    #define TH_MAGENTA "\033[35m"
#endif

// --- Global test filter (set via command line) ---
inline std::string& getTestFilter() {
  static std::string filter = "";
  return filter;
}

inline void setTestFilter(const std::string& f) {
  getTestFilter() = f;
}

inline bool shouldRunTest(const std::string& testName) {
  const std::string& filter = getTestFilter();
  return filter.empty() || testName == filter;
}

// --- Helper macro to parse command line args in main() ---
#define PARSE_TEST_ARGS(argc, argv) \
  do { \
    if (argc > 1) { \
      setTestFilter(argv[1]); \
      std::cerr << "Running only test: " << argv[1] << "\n\n"; \
    } \
  } while(0)


// --- Helper: toString for simple types ---
template <typename T> std::string toString(const T &val) {
  std::ostringstream oss;
  oss << val;
  return oss.str();
}

// --- Helper: toString for std::string (to add quotes) ---
inline std::string toString(const std::string &val) {
  std::ostringstream oss;
  oss << '"' << val << '"';
  return oss.str();
}

// --- Helper: toString for C-string literals ---
inline std::string toString(const char* s) {
  return toString(std::string(s ? s : ""));
}

// --- Helper: toString for std::vector ---
template <typename T> std::string toString(const std::vector<T> &vec) {
  std::ostringstream oss;
  oss << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    oss << toString(vec[i]); // Recursive call to handle nested types
    if (i < vec.size() - 1)
      oss << ", ";
  }
  oss << "]";
  return oss.str();
}

// ---------- Equality helpers ----------
template <typename T>
bool isEqual(const T& a, const T& b) { return a == b; }

// String-vs-literal bridges
inline bool isEqual(const std::string& a, const char* b) {
  return a == std::string(b ? b : "");
}
inline bool isEqual(const char* a, const std::string& b) {
  return std::string(a ? a : "") == b;
}

// Floating-point specialization with tolerance
inline bool isEqual(const double& a, const double& b) {
  // Handle special cases: inf and nan
  if (std::isnan(a) || std::isnan(b)) return false;
  if (std::isinf(a) || std::isinf(b)) return a == b;

  const double eps = 1e-9;
  return std::abs(a - b) <= eps * std::max(1.0, std::max(std::abs(a), std::abs(b)));
}

// ---------- Core test runner (timed by default) ----------
/**
 * @brief Executes a single test case on a solution function, checking both correctness and runtime.
 *
 * This generic test runner is designed to handle any callable that accepts one or more arguments
 * and returns a value to be compared against an expected result. It measures execution time,
 * enforces a time limit, and prints detailed diagnostic output (PASS/FAIL, runtime, expected vs. actual).
 *
 * @tparam Func          Callable type (e.g. lambda, std::function) representing the solution function.
 * @tparam ExpectedType  Type of the expected result (must support operator== and toString()).
 * @tparam Args...       Variadic template parameters representing argument types for the solution.
 *
 * @param testName       Human-readable label for the test (displayed in output).
 * @param solutionFunction Callable to be tested. It should accept `Args...` parameters and return a result.
 * @param expected        The correct expected result for comparison.
 * @param timeLimitMs     Maximum allowed execution time in milliseconds (default = 500 ms).
 * @param args...         Forwarded arguments passed directly to `solutionFunction`.
 */
template <typename Func, typename ExpectedType, typename... Args>
void runTest(const std::string &testName,
             Func solutionFunction,
             const ExpectedType &expected,
             long long timeLimitMs = 500,
             Args&&... args) {

  // Check if we should run this test (based on filter)
  if (!shouldRunTest(testName)) {
    return;  // Skip this test
  }

  // Deduce return type R from the function call.
  using R = std::invoke_result_t<std::decay_t<Func>, std::decay_t<Args>...>;

  // Use a shared promise to transport the result from the worker thread.
  // We use shared_ptr because std::function (used by std::thread) requires
  // copyable closures, but std::promise is move-only.
  auto promise = std::make_shared<std::promise<R>>();
  auto future = promise->get_future();

  // Launch the worker thread.
  // We capture arguments by value (copies) to ensure memory safety.
  // If we passed by reference and the main thread timed out + returned,
  // the detached thread would access dangling stack references -> Segfault.
  std::thread worker(
      [promise, solutionFunction, args...]() mutable {
        try {
          // Handle void return types vs value return types
          if constexpr (std::is_void_v<R>) {
            solutionFunction(args...);
            promise->set_value();
          } else {
            promise->set_value(solutionFunction(args...));
          }
        } catch (...) {
          promise->set_exception(std::current_exception());
        }
      });

  // Measure elapsed time for the waiting period.
  auto start = std::chrono::steady_clock::now();
  std::future_status status =
      future.wait_for(std::chrono::milliseconds(timeLimitMs));
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::steady_clock::now() - start);

  if (status == std::future_status::timeout) {
    // TIMEOUT CASE:
    // We detach the thread so we can stop waiting. The thread continues
    // in the background.
    worker.detach();

    // Flush stderr to ensure any debug output appears before test result
    std::cerr << std::flush;
    std::cerr << TH_MAGENTA << "══════════ Test: " << testName << " ══════════" << TH_RESET << "\n";
    std::cerr << TH_RED << "✗ FAIL" << TH_RESET << " (TLE: " << timeLimitMs << "+ ms)\n\n";
  } else {
    // COMPLETION CASE:
    // Join the thread FIRST to ensure all debug output is complete
    worker.join();
    
    // Now flush stderr to ensure all debug output from worker thread is visible
    std::cerr << std::flush;

    try {
      // Retrieve result (or rethrow exception from worker)
      R result = future.get();
      
      bool correct = isEqual(result, expected);

      std::cerr << TH_MAGENTA << "══════════ Test: " << testName << " ══════════" << TH_RESET << "\n";
      if (!correct) {
        std::cerr << TH_RED << "✗ FAIL" << TH_RESET << " (" << elapsed.count() << " ms)\n"
                  << "  Expected: " << toString(expected) << "\n"
                  << "  Got:      " << toString(result) << "\n\n";
      } else {
        std::cerr << TH_GREEN << "✓ PASS" << TH_RESET << " (" << elapsed.count() << " ms)\n\n";
      }
    } catch (const std::exception& e) {
      std::cerr << TH_MAGENTA << "══════════ Test: " << testName << " ══════════" << TH_RESET << "\n";
      std::cerr << TH_RED << "✗ FAIL" << TH_RESET << " (Exception: " << e.what() << ")\n\n";
    } catch (...) {
      std::cerr << TH_MAGENTA << "══════════ Test: " << testName << " ══════════" << TH_RESET << "\n";
      std::cerr << TH_RED << "✗ FAIL" << TH_RESET << " (Unknown Exception)\n\n";
    }
  }
}

#endif  // LEETCODECHALLENGES_TESTHARNESS_H

