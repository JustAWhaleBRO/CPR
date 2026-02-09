// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

void self_mul(int &a, int b) {
    a = (ll) a * (b % MOD) % MOD;
}

void dfs(int v, int parent, vector<vector<int>> &dp, const vector<vector<int>> &adj) {
    dp[v][0] = 1;
    dp[v][1] = 1;

    for (int neighbor : adj[v]) {
        if (neighbor != parent) {
            dfs(neighbor, v, dp, adj);

            self_mul(dp[v][0], dp[neighbor][1] + dp[neighbor][0]);
            self_mul(dp[v][1], dp[neighbor][0]);
        }
    }
}

ll solve(int N, const vector<int>& x, const vector<int>& y) {
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) {
        adj[x[i]].emplace_back(y[i]);
        adj[y[i]].emplace_back(x[i]);
    }

    // dp[i][j] number of ways to color the subtree rooted at i
    // given i is painted white (j = 0) / black (j = 1)
    vector<vector<int>> dp(N + 1, vector<int>(2));
    dfs(1, -1, dp, adj);

    return ((ll) dp[1][0] + dp[1][1]) % MOD;
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> x(N-1), y(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> x[i] >> y[i];
    }

    cout << solve(N, x, y) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const int& N, const vector<int>& x, const vector<int>& y) -> ll {
        return solve(N, x, y);
    };

    // Sample 1: N=3, edges: (1,2), (2,3)
    // Expected: 5
    runTest("Sample1", solver, 5LL, 500,
        3,
        vector<int>{1, 2},
        vector<int>{2, 3}
    );

    // Sample 2: N=4, edges: (1,2), (1,3), (1,4)
    // Expected: 9
    runTest("Sample2", solver, 9LL, 500,
        4,
        vector<int>{1, 1, 1},
        vector<int>{2, 3, 4}
    );

    // Sample 3: N=1
    // Expected: 2
    runTest("Sample3", solver, 2LL, 500,
        1,
        vector<int>{},
        vector<int>{}
    );

    // Sample 4: N=10
    // Expected: 157
    runTest("Sample4", solver, 157LL, 500,
        10,
        vector<int>{8, 10, 6, 1, 4, 2, 3, 9, 1},
        vector<int>{5, 8, 5, 5, 8, 10, 6, 2, 7}
    );

    return 0;
}
#endif
