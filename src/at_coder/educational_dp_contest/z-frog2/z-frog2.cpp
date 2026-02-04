// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(int N, int K, const vector<int> &h) {
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j <= i + K; j++) {
            if (j < N) {
                int jump_cost = abs(h[i] - h[j]);
                dp[j] = min(dp[j], dp[i] + jump_cost);
            }
        }
    }
    return dp[N - 1];
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
// AtCoder submission mode - reads from stdin
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    cout << solve(N, K, h) << endl;
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================

#ifdef USE_TEST_HARNESS
// Test harness mode - for local testing
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solver = [](int N, int K, const vector<int>& h) {
        return solve(N, K, h);
    };

    // Sample 1
    // Input: 5 3, 10 30 40 50 20
    // Expected: 30
    runTest("Sample1", solver, 30, 2000,
        5, 3, vector<int>{10, 30, 40, 50, 20});

    // Sample 2
    // Input: 3 1, 10 20 10
    // Expected: 20
    runTest("Sample2", solver, 20, 2000,
        3, 1, vector<int>{10, 20, 10});

    // Sample 3
    // Input: 2 100, 10 10
    // Expected: 0
    runTest("Sample3", solver, 0, 2000,
        2, 100, vector<int>{10, 10});

    // Sample 4
    // Input: 10 4, 40 10 20 70 80 10 20 70 80 60
    // Expected: 40
    runTest("Sample4", solver, 40, 2000,
        10, 4, vector<int>{40, 10, 20, 70, 80, 10, 20, 70, 80, 60});

    return 0;
}
#endif

