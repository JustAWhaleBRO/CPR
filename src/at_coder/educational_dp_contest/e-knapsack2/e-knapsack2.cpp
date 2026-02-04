// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

ll solve(int N, int W, const vector<int> &w, const vector<int> &v) {
    int sum_value = 0;
    for (int x : v) sum_value += x;
    vector<ll> dp(sum_value + 1, LLONG_MAX);    // Minium weight for total value i

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        int cur_w = w[i - 1];
        int cur_v = v[i - 1];

        for (int value = sum_value; value >= cur_v; value--) {
            if (dp[value - cur_v] != LLONG_MAX) {
                dp[value] = min(dp[value], dp[value - cur_v] + cur_w);
            }
        }
    }

    for (int val = sum_value; val >= 0; val--) {
        if (dp[val] <= W) {
            return val;
        }
    }
    return -1;
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    int  W;
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

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](int N, int W, const vector<int>& w, const vector<int>& v) -> ll {
        return solve(N, W, w, v);
    };

    // Sample 1
    runTest("Sample1", solver, 90, 5,
        3, 8,
        vector<int>{3, 4, 5},
        vector<int>{30, 50, 60}
    );

    // Sample 2 (large W)
    runTest("Sample2", solver, 10, 5,
        1, 1000000000,
        vector<int>{1000000000},
        vector<int>{10}
    );

    // Sample 3
    runTest("Sample3", solver, 17, 5,
        6, 15,
        vector<int>{6, 5, 6, 6, 3, 7},
        vector<int>{5, 6, 4, 6, 5, 2}
    );

    return 0;
}
#endif
