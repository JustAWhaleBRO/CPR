// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll solve() {
    // TODO: Implement Grid Coloring I solution
    // This is a newer problem - implement based on problem requirements
    return 0;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: Read input based on problem specification

    cout << solve() << "\n";
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = []() -> ll {
        return solve();
    };

    // TODO: Add test cases based on problem specification
    // runTest("Sample1", solver, expected, 1000);

    return 0;
}
#endif

