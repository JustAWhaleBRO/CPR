// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int solve(int N, const vector<int> &h) {
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (i + 1 < N) {
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
        }
        if (i + 2 < N) {
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
        }
    }
    return dp[N - 1];
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    cout << solve(N, h) << endl;
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

    auto solver = [](int N, const vector<int> &h) {
        return solve(N, h);
    };

    // Sample Input 1: 4 / 10 30 40 20 → Expected: 30
    runTest("Sample1", solver, 30, 2000,
        4, vector<int>{10, 30, 40, 20}
    );

    // Sample Input 2: 2 / 10 10 → Expected: 0
    runTest("Sample2", solver, 0, 2000,
        2, vector<int>{10, 10}
    );

    // Sample Input 3: 6 / 30 10 60 10 60 50 → Expected: 40
    runTest("Sample3", solver, 40, 2000,
        6, vector<int>{30, 10, 60, 10, 60, 50}
    );

    return 0;
}
#endif
