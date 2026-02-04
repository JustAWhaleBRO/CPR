// ==================== ATCODER SUBMISSION (copy from here) ====================

#include <iostream>
#include <vector>
#include "Debug.h"

using namespace std;
using ll = long long;

ll solve(int N, const vector<ll>& a) {
    dbg(N, a);  // Print input

    vector<vector<ll>> dp(N, vector<ll>(N)); // dp[L][R] -> Maximum X - Y given the subarray a[L...R]

    // Base case: single element
    for (int i = 0; i < N; i++) {
        dp[i][i] = a[i];
    }
    dbg_section("After base case");
    dbg_dp2d_labeled(dp, "L", "R");

    for (int L = N - 1; L >= 0; L--) {
        for (int R = L; R < N; R++) {

            if (L == R) continue;

            ll takeLeft = a[L] - dp[L + 1][R];
            ll takeRight = a[R] - dp[L][R - 1];
            dp[L][R] = max(takeLeft, takeRight);
            dbg_iter(L, R, takeLeft, takeRight, dp[L][R]);
            dbg_dp2d_labeled(dp, "L", "R");

        }
    }

    dbg_section("Final DP table");
    dbg_dp2d_labeled(dp, "L", "R");
    dbg(dp[0][N - 1]);

    return dp[0][N - 1];
}

#ifndef USE_TEST_HARNESS
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve(N, a) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const int& N, const vector<ll>& a) -> ll {
        return solve(N, a);
    };

    // Sample 1: N=4, a=[10, 80, 90, 30]
    // Expected: 10
    runTest("Sample1", solver, 10LL, 500,
        4,
        vector<ll>{10, 80, 90, 30}
    );

    // Sample 2: N=3, a=[10, 100, 10]
    // Expected: -80
    runTest("Sample2", solver, -80LL, 500,
        3,
        vector<ll>{10, 100, 10}
    );

    // Sample 3: N=1, a=[10]
    // Expected: 10
    runTest("Sample3", solver, 10LL, 500,
        1,
        vector<ll>{10}
    );

    // Sample 4: N=10, a=[1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1]
    // Expected: 4999999995
    runTest("Sample4", solver, 4999999995LL, 500,
        10,
        vector<ll>{1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1}
    );

    // Sample 5: N=6, a=[4, 2, 9, 7, 1, 5]
    // Expected: 2
    runTest("Sample5", solver, 2LL, 500,
        6,
        vector<ll>{4, 2, 9, 7, 1, 5}
    );

    return 0;
}
#endif
