// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <string>
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

    // CSES Example: HATTIVATTI -> AHATITITVT
    runTest("Sample1", solver, string("AHATITITVT"), 1000, string("HATTIVATTI"));

    // Impossible case: all same chars
    runTest("Sample2", solver, string("-1"), 1000, string("AAA"));

    // Simple two chars
    runTest("Sample3", solver, string("ABA"), 1000, string("AAB"));

    // Already valid single char
    runTest("Sample4", solver, string("A"), 1000, string("A"));

    return 0;
}
#endif

