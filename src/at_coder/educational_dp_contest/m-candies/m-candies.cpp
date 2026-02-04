// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include "Debug.h"

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

void add_self(ll &a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

ll solve(int N, int K, const vector<int>& a) {
    vector<ll> dp(K + 1); // dp[i] number of combinations using i candies
    dp[0] = 1;

    for (int child = 0; child < N; child++) {
        for (int used = K; used >= 0; used--) {
            for (int give = 0; give <= min(a[child], used - K); give++) {
                add_self(dp[used + give], dp[used]);
                dbg_iter(child, used, give);
                dbg_dp(dp);

            }
        }
    }
    return dp[K];
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve(N, K, a) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const int N, const int& K, const vector<int>& a) -> ll {
        return solve(N, K, a);
    };

    // Sample 1: N=3, K=4, a=[1, 2, 3]
    // Expected: 5
    runTest("Sample1", solver, 5LL, 500,
        3, 4,
        vector<int>{1, 2, 3}
    );

    // Sample 2: N=1, K=10, a=[9]
    // Expected: 0
    runTest("Sample2", solver, 0LL, 500,
        1, 10,
        vector<int>{9}
    );

    // Sample 3: N=2, K=0, a=[0, 0]
    // Expected: 1
    runTest("Sample3", solver, 1LL, 500,
        2, 0,
        vector<int>{0, 0}
    );

    // Sample 4: N=4, K=100000, a=[100000, 100000, 100000, 100000]
    // Expected: 665683269
    runTest("Sample4", solver, 665683269LL, 500,
        4, 100000,
        vector<int>{100000, 100000, 100000, 100000}
    );

    return 0;
}
#endif
