// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll solve(int N, const vector<vector<int>>& compatibility) {
    // TODO: Implement the solution
    return 0;
}

#ifndef USE_TEST_HARNESS
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> compatibility(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> compatibility[i][j];
        }
    }

    cout << solve(N, compatibility) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const vector<vector<int>>& compatibility) -> ll {
        return solve(N, compatibility);
    };

    // Sample 1: N=3
    // Expected: 3
    runTest("Sample1", solver, 3LL, 500,
        3,
        vector<vector<int>>{
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
        }
    );

    // Sample 2: N=4
    // Expected: 1
    runTest("Sample2", solver, 1LL, 500,
        4,
        vector<vector<int>>{
            {0, 1, 0, 0},
            {0, 0, 0, 1},
            {1, 0, 0, 0},
            {0, 0, 1, 0}
        }
    );

    // Sample 3: N=1
    // Expected: 0
    runTest("Sample3", solver, 0LL, 500,
        1,
        vector<vector<int>>{
            {0}
        }
    );

    // Sample 4: N=21
    // Expected: 102557693
    runTest("Sample4", solver, 102557693LL, 500,
        21,
        vector<vector<int>>{
            {0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,0,0,1,0,0,1},
            {1,1,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,1,0},
            {0,0,1,1,1,1,0,1,1,0,0,1,0,0,1,1,1,0,0,0,1},
            {0,1,1,0,1,1,0,1,0,1,0,0,1,0,0,1,1,1,0,0,0},
            {1,1,0,0,1,0,1,0,0,1,1,1,0,0,1,0,0,0,0,1,1},
            {0,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1,0,0,1,1,0},
            {0,1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1},
            {0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1},
            {0,0,1,0,1,1,0,0,0,1,1,1,0,0,1,0,1,0,1,1,1},
            {0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0},
            {1,1,1,0,1,1,0,0,1,1,0,1,0,1,1,0,1,0,0,0,1},
            {0,0,1,1,0,1,0,0,1,0,0,0,0,0,1,1,0,1,0,1,1},
            {0,1,1,0,0,1,0,0,1,0,1,1,1,0,0,0,0,0,1,1,0},
            {1,0,0,1,1,0,1,1,0,1,1,0,1,0,0,1,1,1,0,0,1},
            {0,0,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,0,1,0,0},
            {0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1},
            {0,0,0,1,0,0,1,1,1,0,0,0,1,1,0,1,1,0,1,1,0},
            {0,0,1,1,0,1,1,1,0,1,0,1,1,0,1,0,1,1,1,0,0},
            {1,1,1,0,1,0,0,1,1,1,1,0,0,1,0,1,1,0,1,0,1},
            {0,0,1,1,0,1,1,1,1,1,0,1,1,0,0,1,0,1,0,1,1},
            {0,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,0}
        }
    );

    return 0;
}
#endif
