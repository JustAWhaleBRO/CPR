// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
using namespace std;
using ll = long long;

ll solve(ll n) {
    // TODO: Implement solution
    return 0;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](ll n) -> ll {
        return solve(n);
    };

    // Sample 1: n=20 -> 4 trailing zeros
    runTest("Sample1", solver, 4LL, 1000, 20LL);

    // n=5 -> 1
    runTest("Sample2", solver, 1LL, 1000, 5LL);

    // n=25 -> 6 (5, 10, 15, 20, 25 gives 6)
    runTest("Sample3", solver, 6LL, 1000, 25LL);

    // n=100 -> 24
    runTest("Sample4", solver, 24LL, 1000, 100LL);

    return 0;
}
#endif
