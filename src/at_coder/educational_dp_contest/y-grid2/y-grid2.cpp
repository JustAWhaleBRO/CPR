// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll solve(ll H, ll W, int N, const vector<ll>& r, const vector<ll>& c) {
    // TODO: Implement the solution
    return 0;
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll H, W;
    int N;
    cin >> H >> W >> N;

    vector<ll> r(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i] >> c[i];
    }

    cout << solve(H, W, N, r, c) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const ll& H, const ll& W, const int& N, const vector<ll>& r, const vector<ll>& c) -> ll {
        return solve(H, W, N, r, c);
    };

    // Sample 1: H=2, W=3, N=1, walls: (2,2)
    // Expected: 2
    runTest("Sample1", solver, 2LL, 500,
        2LL, 3LL, 1,
        vector<ll>{2},
        vector<ll>{2}
    );

    // Sample 2: H=2, W=2, N=1, walls: (2,2)
    // Expected: 0
    runTest("Sample2", solver, 0LL, 500,
        2LL, 2LL, 1,
        vector<ll>{2},
        vector<ll>{2}
    );

    // Sample 3: H=3, W=3, N=2, walls: (2,3), (3,2)
    // Expected: 2
    runTest("Sample3", solver, 2LL, 500,
        3LL, 3LL, 2,
        vector<ll>{2, 3},
        vector<ll>{3, 2}
    );

    // Sample 4: H=100000, W=100000, N=3, walls: (1,1), (50000,50000), (100000,100000)
    // Expected: 1
    runTest("Sample4", solver, 1LL, 500,
        100000LL, 100000LL, 3,
        vector<ll>{1, 50000, 100000},
        vector<ll>{1, 50000, 100000}
    );

    return 0;
}
#endif
