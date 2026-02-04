// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(int N, int K, const vector<int>& a) {
    // TODO: Implement the solution
    return "First";
}

#ifndef USE_TEST_HARNESS
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

    return 0;
}
#endif
