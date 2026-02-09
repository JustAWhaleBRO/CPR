// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

void self_add(ll &a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

ll solve(int N, ll K, const vector<vector<int>>& adj) {
    vector<ll> dp(N, 1); // number of paths that reach i (paths of any length including 0)
    for (ll steps = 0; steps < K; steps++) {
        vector<ll> new_dp(N);

        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                if (adj[u][v]) {
                    self_add(new_dp[v], dp[u]);
                }
            }
        }
        dp = new_dp;
    }
    ll answer = 0;
    for (const ll val : dp) {
        self_add(answer, val);
    }
    return answer;;
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<vector<int>> adj(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    cout << solve(N, K, adj) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const int& N, const ll& K, const vector<vector<int>>& adj) -> ll {
        return solve(N, K, adj);
    };

    // Sample 1: N=4, K=2
    // Expected: 6
    runTest("Sample1", solver, 6LL, 500,
        4, 2LL,
        vector<vector<int>>{
            {0, 1, 0, 0},
            {0, 0, 1, 1},
            {0, 0, 0, 1},
            {1, 0, 0, 0}
        }
    );

    // Sample 2: N=3, K=3
    // Expected: 3
    runTest("Sample2", solver, 3LL, 500,
        3, 3LL,
        vector<vector<int>>{
            {0, 1, 0},
            {1, 0, 1},
            {0, 0, 0}
        }
    );

    // Sample 3: N=6, K=2
    // Expected: 1
    runTest("Sample3", solver, 1LL, 500,
        6, 2LL,
        vector<vector<int>>{
            {0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0}
        }
    );

    // Sample 4: N=1, K=1
    // Expected: 0
    runTest("Sample4", solver, 0LL, 500,
        1, 1LL,
        vector<vector<int>>{
            {0}
        }
    );

    // Sample 5: N=10, K=1000000000000000000
    // Expected: 957538352
    runTest("Sample5", solver, 957538352LL, 500,
        10, 1000000000000000000LL,
        vector<vector<int>>{
            {0,0,1,1,0,0,0,1,1,0},
            {0,0,0,0,0,1,1,1,0,0},
            {0,1,0,0,0,1,0,1,0,1},
            {1,1,1,0,1,1,0,1,1,0},
            {0,1,1,1,0,1,0,1,1,1},
            {0,0,0,1,0,0,1,0,1,0},
            {0,0,0,1,1,0,0,1,0,1},
            {1,0,0,0,1,0,1,0,0,0},
            {0,0,0,0,0,1,0,0,0,0},
            {1,0,1,1,1,0,1,1,1,0}
        }
    );

    return 0;
}
#endif
