// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <format>

using namespace std;

double solve(int N, const vector<double> &p) {
    vector<double> dp(N + 1, 0.0);
    dp[0] = 1.0;
    for (int i = 1; i <= N; i++) {
        double p_heads = p[i - 1];
        double p_tails = 1.0 - p_heads;

        for (int j = N; j >= 0; j--) {
            dp[j] *= p_tails;

            if (j > 0) {
                dp[j] += dp[j - 1] * p_heads;
            }
        }
    }
    double ans = 0.0;
    for (int j = N / 2 + 1; j <= N; j++) {
        ans += dp[j];
    }
    return ans;
}
// double solve(int N, const vector<double>& p) {
//     vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0.0)); // dp[i][j] := after i coins, j heads
//     dp[0][0] = 1.0;
//
//     for (int i = 1; i <= N; i++) {
//         double p_heads = p[i - 1];
//         double p_tails = 1.0 - p_heads;
//
//         for (int j = 0; j <= i; j++) {
//             dp[i][j] += dp[i - 1][j] * p_tails;
//
//             if (j > 0) {
//                 dp[i][j] += dp[i - 1][j - 1] * p_heads;
//             }
//         }
//     }
//     double ans = 0.0;
//     for (int j = (N / 2) + 1; j <= N; j++) {
//         ans += dp[N][j];
//     }
//
//     return ans;
// }

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<double> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    cout << format("{:.10f}", solve(N, p)) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const vector<double>& p) -> double {
        return solve(N, p);
    };

    // Sample 1: N=3, probabilities: 0.30, 0.60, 0.80
    // Expected: 0.612
    runTest("Sample1", solver, 0.612, 500,
        3,
        vector<double>{0.30, 0.60, 0.80}
    );

    // Sample 2: N=1, probability: 0.50
    // Expected: 0.5
    runTest("Sample2", solver, 0.5, 500,
        1,
        vector<double>{0.50}
    );

    // Sample 3: N=5, probabilities: 0.42, 0.01, 0.42, 0.99, 0.42
    // Expected: 0.3821815872
    runTest("Sample3", solver, 0.3821815872, 500,
        5,
        vector<double>{0.42, 0.01, 0.42, 0.99, 0.42}
    );

    return 0;
}
#endif
