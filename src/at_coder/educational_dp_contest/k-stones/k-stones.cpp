// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(int N, int K, const vector<int>& a) {
    vector<bool> dp(K + 1, false);
    for (int stones = 0; stones <= K; stones++) {
        for (int x : a) {
            if (x <= stones && !dp[stones - x]) {
                dp[stones] = true;
            }
        }
    }
    return dp[K] ? "First" : "Second";
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve(N, K, a) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const int& K, const vector<int>& a) -> string {
        return solve(N, K, a);
    };

    // Sample 1: N=2, K=4, a=[2, 3]
    // Expected: First
    runTest("Sample1", solver, string("First"), 500,
        2, 4,
        vector<int>{2, 3}
    );

    // Sample 2: N=2, K=5, a=[2, 3]
    // Expected: Second
    runTest("Sample2", solver, string("Second"), 500,
        2, 5,
        vector<int>{2, 3}
    );

    // Sample 3: N=2, K=7, a=[2, 3]
    // Expected: First
    runTest("Sample3", solver, string("First"), 500,
        2, 7,
        vector<int>{2, 3}
    );

    // Sample 4: N=3, K=20, a=[1, 2, 3]
    // Expected: Second
    runTest("Sample4", solver, string("Second"), 500,
        3, 20,
        vector<int>{1, 2, 3}
    );

    // Sample 5: N=3, K=21, a=[1, 2, 3]
    // Expected: First
    runTest("Sample5", solver, string("First"), 500,
        3, 21,
        vector<int>{1, 2, 3}
    );

    // Sample 6: N=1, K=100000, a=[1]
    // Expected: Second
    runTest("Sample6", solver, string("Second"), 500,
        1, 100000,
        vector<int>{1}
    );

    return 0;
}
#endif
