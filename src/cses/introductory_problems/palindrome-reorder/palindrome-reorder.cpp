// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string solve(const string& s) {
    // TODO: Implement solution
    return "";
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

    auto solver = [](const string& s) -> string {
        return solve(s);
    };

    // Sample 1: AAAACACBA -> AACABACAA (or similar)
    runTest("Sample1", solver, string("AACABACAA"), 1000, string("AAAACACBA"));

    // Impossible case
    runTest("Sample2", solver, string("NO SOLUTION"), 1000, string("ABC"));

    // Single char
    runTest("Sample3", solver, string("A"), 1000, string("A"));

    return 0;
}
#endif
