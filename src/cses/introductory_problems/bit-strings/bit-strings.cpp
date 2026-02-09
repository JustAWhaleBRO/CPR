// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll solve(int n) {
    // TODO: Implement solution
    return 0;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
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

    auto solver = [](int n) -> ll {
        return solve(n);
    };

    // Sample 1: n=3 -> 2^3 = 8
    runTest("Sample1", solver, 8LL, 1000, 3);

    // n=1 -> 2
    runTest("Sample2", solver, 2LL, 1000, 1);

    // n=10 -> 1024
    runTest("Sample3", solver, 1024LL, 1000, 10);

    return 0;
}
#endif
