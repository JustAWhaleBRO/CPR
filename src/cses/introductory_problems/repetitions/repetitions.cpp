// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <string>
using namespace std;

int solve(const string& s) {
    // TODO: Implement solution
    return 0;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << solve(s) << "\n";
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const string& s) -> int {
        return solve(s);
    };

    // Sample 1: ATTCGGGA -> longest is GGG = 3
    runTest("Sample1", solver, 3, 1000, string("ATTCGGGA"));

    // Additional: single char
    runTest("Sample2", solver, 1, 1000, string("A"));

    // Additional: all same
    runTest("Sample3", solver, 5, 1000, string("AAAAA"));

    return 0;
}
#endif

