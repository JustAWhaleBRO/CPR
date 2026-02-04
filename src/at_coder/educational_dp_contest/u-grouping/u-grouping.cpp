// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll solve(int N, const vector<vector<ll>>& a) {
    // TODO: Implement the solution
    return 0;
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<ll>> a(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve(N, a) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const vector<vector<ll>>& a) -> ll {
        return solve(N, a);
    };

    // Sample 1: N=3
    // Expected: 6
    runTest("Sample1", solver, 6LL, 500,
        3,
        vector<vector<ll>>{
            {0, -1, -2},
            {-1, 0, -3},
            {-2, -3, 0}
        }
    );

    // Sample 2: N=4
    // Expected: 0
    runTest("Sample2", solver, 0LL, 500,
        4,
        vector<vector<ll>>{
            {0, -1, -1, -1},
            {-1, 0, -1, -1},
            {-1, -1, 0, -1},
            {-1, -1, -1, 0}
        }
    );

    // Sample 3: N=16
    // Expected: 283
    runTest("Sample3", solver, 283LL, 500,
        16,
        vector<vector<ll>>{
            {0,3,0,1,2,0,1,3,2,2,2,0,1,0,2,2},
            {3,0,2,1,0,2,2,0,2,2,1,2,2,3,1,3},
            {0,2,0,2,2,3,2,1,1,0,3,1,3,2,2,3},
            {1,1,2,0,1,1,0,3,1,3,1,3,3,3,1,2},
            {2,0,2,1,0,0,1,3,0,0,2,0,2,2,3,2},
            {0,2,3,1,0,0,3,0,1,3,1,2,3,3,0,3},
            {1,2,2,0,1,3,0,3,1,2,1,3,3,3,3,3},
            {3,0,1,3,3,0,3,0,2,1,2,2,3,3,0,1},
            {2,2,1,1,0,1,1,2,0,3,2,1,2,0,3,0},
            {2,2,0,3,0,3,2,1,3,0,3,2,0,3,2,2},
            {2,1,3,1,2,1,1,2,2,3,0,0,3,2,2,3},
            {0,2,1,3,0,2,3,2,1,2,0,0,0,1,3,3},
            {1,2,3,3,2,3,3,3,2,0,3,0,0,2,0,1},
            {0,3,2,3,2,3,3,3,0,3,2,1,2,0,2,0},
            {2,1,2,1,3,0,3,0,3,2,2,3,0,2,0,1},
            {2,3,3,2,2,3,3,1,0,2,3,3,1,0,1,0}
        }
    );

    return 0;
}
#endif
