// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
// Solve knapsack: N items, capacity W, weights w[i], values v[i]
// ll solve(int N, int W, const vector<int>& w, const vector<int>& v) {
//     vector<ll> dp(W + 1, 0); // Maximum total value of items with i weight
//     for (int i = 0; i < N; i++) {
//         int weight = w[i];
//         int value = v[i];
//
//         for (int j = W; j >= weight; j--) {
//             dp[j] = max(dp[j], dp[j - weight] + value);
//         }
//     }
//     return dp[W];
// }

ll solve(int N, int W, const vector<int> &w, const vector<int> &v) {
    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        int curr_w = w[i - 1];
        int cur_val = v[i - 1];

        for (int weight = 0; weight <= W; weight++) {
            dp[i][weight] = dp[i - 1][weight];

            if (curr_w <= weight) {
                dp[i][weight] = max(dp[i - 1][weight - curr_w] + cur_val, dp[i][weight]);
            }
        }
    }
    return dp[N][W];
}

#ifndef USE_TEST_HARNESS
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, W;
    cin >> N >> W;
    vector<int> w(N);
    vector<int> v(N);
    for (int i = 0; i < N; ++i) std::cin >> w[i] >> v[i];
    std::cout << solve(N, W, w, v) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {
    auto solver = [](int N, int W, const vector<int>& w, const vector<int>& v) -> ll {
        return solve(N, W, w, v);
    };

    // Sample 1
    runTest("Sample1", solver, 90, 200,
        3, 8,
        vector<int>{3,4,5},
        vector<int>{30,50,60}
    );

    // Sample 2 (will overflow 32-bit; this implementation caps at INT_MAX)
    runTest("Sample2", solver, 5000000000, 200,
        5, 5,
        vector<int>{1,1,1,1,1},
        vector<int>{1000000000,1000000000,1000000000,1000000000,1000000000}
    );

    // Sample 3
    runTest("Sample3", solver, 17, 200,
        6, 15,
        vector<int>{6,5,6,6,3,7},
        vector<int>{5,6,4,6,5,2}
    );

    return 0;
}
#endif
