/**
 * =========================================================
 * HACKERRANK "STACK BATCH REMOVAL" - RIGOROUS SOLUTION & TESTER
 * =========================================================
 * * Author: Gemini (Your Friendly CS Professor)
 * * Complexity: O(N log N) using Dual-Structure Indexing (List + Multimap)
 * * Status: Optimized for 2*10^5 operations.
 */

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <iterator>
#include <sstream>
#include <iomanip>

// =========================================================
//  PART 1: THE CORE SOLUTION
// =========================================================

// Forward declaration
struct StackNode;

// The stack sequence is maintained in a list (stable iterators).
using StackList = std::list<StackNode>;

// The value index maps integer values to their position in the StackList.
using ValueIndex = std::multimap<int, StackList::iterator>;

struct StackNode {
    int value;
    ValueIndex::iterator map_ref; // Cross-link to map
};

class BatchStack {
public:
    // Helper to capture output for testing vs printing to stdout
    std::vector<std::string> process_commands(const std::vector<std::string>& commands) {
        std::vector<std::string> results;
        reset(); // Ensure fresh state

        for (const auto& cmd_line : commands) {
            std::stringstream ss(cmd_line);
            std::string operation;
            ss >> operation;

            if (operation == "push") {
                int val;
                ss >> val;
                push(val);
            } else if (operation == "pop") {
                pop();
            } else if (operation == "remove_lower") {
                int val;
                ss >> val;
                remove_lower(val);
            } else if (operation == "remove_upper") {
                int val;
                ss >> val;
                remove_upper(val);
            }

            results.push_back(get_top());
        }
        return results;
    }

private:
    StackList stack_seq_;
    ValueIndex val_index_;

    void reset() {
        stack_seq_.clear();
        val_index_.clear();
    }

    void push(int val) {
        stack_seq_.push_back({val, {}});
        auto list_it = std::prev(stack_seq_.end());
        auto map_it = val_index_.insert({val, list_it});
        list_it->map_ref = map_it;
    }

    void pop() {
        if (stack_seq_.empty()) return;
        auto list_it = std::prev(stack_seq_.end());
        val_index_.erase(list_it->map_ref);
        stack_seq_.pop_back();
    }

    void remove_lower(int threshold) {
        // lower_bound returns iterator to first element >= threshold
        // So begin() to lower_bound() covers everything < threshold
        auto end_it = val_index_.lower_bound(threshold);
        auto it = val_index_.begin();
        while (it != end_it) {
            stack_seq_.erase(it->second);
            it = val_index_.erase(it);
        }
    }

    void remove_upper(int threshold) {
        // upper_bound returns iterator to first element > threshold
        // So upper_bound() to end() covers everything > threshold
        auto it = val_index_.upper_bound(threshold);
        while (it != val_index_.end()) {
            stack_seq_.erase(it->second);
            it = val_index_.erase(it);
        }
    }

    std::string get_top() const {
        if (stack_seq_.empty()) {
            return "EMPTY";
        } else {
            return std::to_string(stack_seq_.back().value);
        }
    }
};


// =========================================================
//  PART 2: THE TEST HARNESS (For Local Verification)
// =========================================================

void runTest(std::string name,
             const std::vector<std::string>& inputs,
             const std::vector<std::string>& expected) {

    std::cout << "[TEST] " << std::left << std::setw(25) << name << " | ";

    BatchStack solver;
    std::vector<std::string> actual = solver.process_commands(inputs);

    if (actual == expected) {
        std::cout << "PASSED" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
        std::cout << "  Expected vs Actual:" << std::endl;
        size_t len = std::max(actual.size(), expected.size());
        for (size_t i = 0; i < len; ++i) {
            std::string exp = (i < expected.size()) ? expected[i] : "(none)";
            std::string act = (i < actual.size()) ? actual[i] : "(none)";
            if (exp != act) {
                std::cout << "   Line " << i+1 << ": " << exp << " != " << act << " <--" << std::endl;
            }
        }
    }
}

void runAllTests() {
    std::cout << "\n=== Running Stack Batch Removal Test Suite ===\n" << std::endl;

    // Case 0: Sample 0 from Screenshot
    runTest("Sample Case 0",
        {
            "push 3", "push 2", "push 4",
            "remove_lower 3", "remove_upper 3",
            "push 2", "pop", "pop"
        },
        { "3", "2", "4", "4", "3", "2", "3", "EMPTY" }
    );

    // Case 1: Sample 1 from Screenshot
    runTest("Sample Case 1",
        {
            "push 2",
            "remove_lower 2",
            "remove_lower 3",
            "push 5"
        },
        { "2", "2", "EMPTY", "5" }
    );

    // Case 2: Pop Empty Stack
    runTest("Pop Empty",
        { "pop", "push 10", "pop", "pop" },
        { "EMPTY", "10", "EMPTY", "EMPTY" }
    );

    // Case 3: Massive Removal (All)
    runTest("Remove All",
        { "push 10", "push 20", "push 30", "remove_lower 100" },
        { "10", "20", "30", "EMPTY" }
    );

    // Case 4: Non-destructive Removal
    runTest("Remove None",
        { "push 10", "push 20", "remove_upper 30", "remove_lower 5" },
        { "10", "20", "20", "20" }
    );

    std::cout << "\n=== Tests Complete ===\n" << std::endl;
}


// =========================================================
//  PART 3: THE MAIN FUNCTION (Standard Input Processing)
// =========================================================

int main() {
    // 1. Run local tests
    runAllTests();

    // 2. Standard Input Processing (HackerRank Mode)
    // To use: Paste the input block into the console after "Waiting for Standard Input..."

    std::cout << "Waiting for Standard Input (Paste your case below or pipe file)..." << std::endl;
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        std::vector<std::string> commands;
        commands.reserve(n);

        // Consume newline after N
        std::string dummy;
        std::getline(std::cin, dummy);

        for (int i = 0; i < n; ++i) {
            std::string line;
            std::getline(std::cin, line);
            if (!line.empty()) {
                commands.push_back(line);
            }
        }

        BatchStack solver;
        std::vector<std::string> output = solver.process_commands(commands);

        for (const auto& line : output) {
            std::cout << line << "\n";
        }
    }

    return 0;
}