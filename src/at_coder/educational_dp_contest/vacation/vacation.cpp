// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
using namespace std;

// int solve(int N, const vector<int>& a, const vector<int>& b, const vector<int>& c) {
//     vector<vector<int>> dp(N, vector<int>(3, 0)); // max hapiness on day i ending with activity j
//     dp[0][0] = a[0];
//     dp[0][1] = b[0];
//     dp[0][2] = c[0];
//
//     for (int day = 1; day < N; day++) {
//         dp[day][0] = max(dp[day - 1][1], dp[day - 1][2]) + a[day];
//         dp[day][1] = max(dp[day - 1][0], dp[day - 1][2]) + b[day];
//         dp[day][2] = max(dp[day - 1][1], dp[day - 1][0]) + c[day];
//     }
//
//     return max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
// }

int solve(int N, const vector<int>& a, const vector<int>& b, const vector<int>& c) {
    vector<int> next_dp(3);
    vector<int> dp(3);
    dp[0] = a[0];
    dp[1] = b[0];
    dp[2] = c[0];


    for (int day = 1; day < N; day++) {
        next_dp[0] = max(dp[1], dp[2]) + a[day];
        next_dp[1] = max(dp[0], dp[2]) + b[day];
        next_dp[2] = max(dp[1], dp[0]) + c[day];

        dp = next_dp;
    }
    return max({dp[0], dp[1], dp[2]});
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; ++i) cin >> a[i] >> b[i] >> c[i];
    cout << solve(N, a, b, c) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solver = [](int N, const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        return solve(N, a, b, c);
    };

    // Sample Input 1
    // 3
    // 10 40 70
    // 20 50 80
    // 30 60 90
    runTest("Sample1", solver, 210LL, 2000,
        3,
        vector<int>{10,20,30},
        vector<int>{40,50,60},
        vector<int>{70,80,90}
    );

    // Sample Input 2
    // 1
    // 100 10 1
    runTest("Sample2", solver, 100LL, 2000,
        1,
        vector<int>{100},
        vector<int>{10},
        vector<int>{1}
    );

    // Sample Input 3
    // 7
    // 6 7 8
    // 8 8 3
    // 2 5 2
    // 7 8 6
    // 4 6 8
    // 2 3 4
    // 7 5 1
    runTest("Sample3", solver, 46LL, 2000,
        7,
        vector<int>{6,8,2,7,4,2,7},
        vector<int>{7,8,5,8,6,3,5},
        vector<int>{8,3,2,6,8,4,1}
    );

    return 0;
}
#endif
