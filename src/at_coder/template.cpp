// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    // TODO: Implement solution
    return 0;
}

#ifndef USE_TEST_HARNESS
// AtCoder submission mode - reads from stdin
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: Read input

    cout << solve() << endl;
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================

#ifdef USE_TEST_HARNESS
// Test harness mode - for local testing
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solver = []() {
        return solve();
    };

    // TODO: Add test cases
    // runTest("Sample1", solver, expected_value, time_limit_ms, args...);

    return 0;
}
#endif

