// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Solve knapsack: N items, capacity W, weights w[i], values v[i]
int solve(int N, int W, const vector<int>& w, const vector<int>& v) {
    vector<int> dp(W + 1, 0); // Maximum total value of items with i weight exactly
    for (int i = 0; i < N; i++) {
        int weight = w[i];
        int value = v[i];

        for (int weight_already = W - weight; weight_already >= 0; weight_already--) {
            dp[weight_already + weight] = max(dp[weight_already + weight], dp[weight_already] + value);
        }
    }
    return *max_element(dp.begin(), dp.end());
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
    auto solver = [](int N, int W, const vector<int>& w, const vector<int>& v) -> int {
        return solve(N, W, w, v);
    };

    // Sample 1
    runTest("Sample1", solver, 90, 200,
        3, 8,
        vector<int>{3,4,5},
        vector<int>{30,50,60}
    );

    // Sample 2 (will overflow 32-bit; this implementation caps at INT_MAX)
    runTest("Sample2", solver, INT_MAX, 200,
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
