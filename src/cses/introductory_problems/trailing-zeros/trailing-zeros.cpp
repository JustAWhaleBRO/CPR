// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
using namespace std;
using ll = long long;

ll solve(int n) {
    ll count = 0;
    while (n > 0) {
        count += n / 5;
        n /= 5;
    }
    return count;
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

    // Sample 1: n=20 -> 4 trailing zeros
    runTest("Sample1", solver, 4LL, 1000, 20);

    return 0;
}
#endif
