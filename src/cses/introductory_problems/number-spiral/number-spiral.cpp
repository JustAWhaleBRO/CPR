// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
using namespace std;
using ll = long long;

ll solve(ll row, ll col) {
    int layer = max(row, col);
    if (layer % 2 == 0) {
        swap(row, col);
    }
    if (row == layer) {
        return (row - 1) * (row - 1) + 1 + (col - 1);

    } else {
        return col * col - (row - 1);
    }

}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        cout << solve(y, x) << "\n";
    }
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](ll y, ll x) -> ll {
        return solve(y, x);
    };

    // Sample 1: (2,3) -> 8
    runTest("Sample1", solver, 8LL, 1000, 2LL, 3LL);

    // Sample 2: (1,1) -> 1
    runTest("Sample2", solver, 1LL, 1000, 1LL, 1LL);

    // Sample 3: (4,2) -> 15
    runTest("Sample3", solver, 15LL, 1000, 4LL, 2LL);

    return 0;
}
#endif

