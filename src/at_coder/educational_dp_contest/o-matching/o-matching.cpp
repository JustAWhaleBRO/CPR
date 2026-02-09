// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <bit>
#include "Debug.h"

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

void self_add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int solve(int N, const vector<vector<int>>& compatibility) {
    // row_mask[i] has j-th bit set if man i can match woman j
    vector<int> row_mask(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (compatibility[i][j]) {
                row_mask[i] |= (1 << j);
            }
        }
    }

    vector<int> dp(1 << N); // dp[i] number of ways to reach state with mask i
    dp[0] = 1;
    for (int mask = 0; mask < (1 << N) - 1; mask++) {

        // Unreachable state
        if (dp[mask] == 0) continue;

        // bitmask of available women - has j-th bit set if woman j is available for i-th man
        int man = popcount((unsigned int) mask);
        unsigned int available_women = row_mask[man] & ~mask;

        // go over all the available women
        while (available_women > 0) {

            // get the woman with the least significant bit first
            int woman_idx = countr_zero(available_women);

            // next taken state is now considered with woman_idx as taken
            int next_mask = mask | (1 << woman_idx);
            self_add(dp[next_mask], dp[mask]);

            available_women ^= (1 << woman_idx);
        }
    }

    return dp[(1 << N) - 1];
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
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

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const int& N, const vector<vector<int>>& compatibility) -> ll {
        return solve(N, compatibility);
    };

    // Sample 1: N=3
    // Expected: 3
    runTest("Sample1", solver, 3, 500,
        3,
        vector<vector<int>>{
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
        }
    );

    // Sample 2: N=4
    // Expected: 1
    runTest("Sample2", solver, 1, 500,
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
    runTest("Sample3", solver, 0, 500,
        1,
        vector<vector<int>>{
            {0}
        }
    );

    // Sample 4: N=21
    // Expected: 102515160
    runTest("Sample4", solver, 102515160, 500,
        21,
        vector<vector<int>>{
            {0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,0,0,1,0,0,1},
            {1,1,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,1,0},
            {0,0,1,1,1,1,0,1,1,0,0,1,0,0,1,1,0,0,0,1,1},
            {0,1,1,0,1,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0},
            {1,1,0,0,1,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
            {0,1,1,0,1,1,1,0,1,1,1,0,0,0,1,1,1,1,0,0,1},
            {0,1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,1,1,0,1,0},
            {0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1},
            {0,0,1,0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1,1,1},
            {0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,1,1,0,0,0,1},
            {0,1,1,0,1,1,0,0,1,1,0,0,0,1,1,1,1,0,1,1,0},
            {0,0,1,0,0,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,1},
            {0,1,1,0,0,1,1,1,1,0,0,0,1,0,1,1,0,1,0,1,1},
            {1,1,1,1,1,0,0,0,0,1,0,0,1,1,0,1,1,1,0,0,1},
            {0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1},
            {1,0,1,1,0,1,0,1,0,0,1,0,0,1,1,0,1,0,1,1,0},
            {0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1},
            {0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,0,0,1,1,0,1},
            {0,0,0,0,1,1,1,0,1,0,1,1,1,0,1,1,0,0,1,1,0},
            {1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,0},
            {1,0,0,1,1,0,1,1,1,1,1,0,1,0,1,1,0,0,0,0,0}
        }
    );

    // Sample 5: N=1
    // Expected: 0
    runTest("Sample5", solver, 2, 500,
        2,
        vector<vector<int>>{
            {1, 1},
            {1, 1}
        }
    );

    return 0;
}
#endif
