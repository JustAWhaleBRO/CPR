// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll solve(int N, ll K, const vector<vector<int>>& adj) {
    // TODO: Implement the solution
    return 0;
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

int main() {

    auto solver = [](const int& N, const ll& K, const vector<vector<int>>& adj) -> ll {
        return solve(N, K, adj);
    };

    // Sample 1: N=4, K=2
    // Expected: 56
    runTest("Sample1", solver, 56LL, 500,
        4, 2LL,
        vector<vector<int>>{
            {0, 1, 0, 0},
            {0, 0, 1, 1},
            {0, 0, 0, 1},
            {1, 0, 0, 0}
        }
    );

    // Sample 2: N=3, K=3
    // Expected: 0
    runTest("Sample2", solver, 0LL, 500,
        3, 3LL,
        vector<vector<int>>{
            {0, 1, 0},
            {1, 0, 0},
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

    // Sample 4: N=10, K=1000000000000000000
    // Expected: 957538352
    runTest("Sample4", solver, 957538352LL, 500,
        10, 1000000000000000000LL,
        vector<vector<int>>{
            {0,1,1,1,0,0,1,0,1,1},
            {0,0,0,0,0,1,1,1,1,0},
            {0,1,0,0,1,1,0,0,0,1},
            {1,1,0,0,1,0,1,0,0,0},
            {0,1,1,0,0,1,0,1,1,0},
            {1,1,0,1,1,0,0,0,0,1},
            {0,1,0,1,1,1,0,1,0,0},
            {1,0,0,0,1,0,0,0,1,0},
            {0,0,0,1,0,1,0,1,0,1},
            {0,0,0,0,1,1,1,1,1,0}
        }
    );

    return 0;
}
#endif
