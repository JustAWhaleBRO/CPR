// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int solve(int N, int M, const vector<int>& x, const vector<int>& y) {
    vector<vector<int>> adj(N + 1);
    vector<int> indegrees(N + 1);

    for (int i = 0; i < M; i++) {
        adj[x[i]].emplace_back(y[i]);
        indegrees[y[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegrees[i] == 0) {
            q.emplace(i);
        }
    }

    vector<int> dp(N + 1, 0);
    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (int u : adj[v]) {
            dp[u] = max(dp[u], dp[v] + 1);

            if (--indegrees[u] == 0) {
                q.emplace(u);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> x(M), y(M);
    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i];
    }

    cout << solve(N, M, x, y) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const int& M, const vector<int>& x, const vector<int>& y) -> int {
        return solve(N, M, x, y);
    };

    // Sample 1: N=4, M=5
    // Edges: (1,2), (1,3), (3,2), (2,4), (3,4)
    // Expected: 3
    runTest("Sample1", solver, 3, 1,
        4, 5,
        vector<int>{1, 1, 3, 2, 3},
        vector<int>{2, 3, 2, 4, 4}
    );

    // Sample 2: N=6, M=3
    // Edges: (2,3), (4,5), (5,6)
    // Expected: 2
    runTest("Sample2", solver, 2, 1,
        6, 3,
        vector<int>{2, 4, 5},
        vector<int>{3, 5, 6}
    );

    // Sample 3: N=5, M=8
    // Edges: (5,3), (2,3), (2,4), (5,2), (5,1), (1,4), (4,3), (1,3)
    // Expected: 3
    runTest("Sample3", solver, 3, 1,
        5, 8,
        vector<int>{5, 2, 2, 5, 5, 1, 4, 1},
        vector<int>{3, 3, 4, 2, 1, 4, 3, 3}
    );

    return 0;
}
#endif
