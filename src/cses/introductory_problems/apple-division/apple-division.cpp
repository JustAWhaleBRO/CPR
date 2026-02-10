// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

ll solve(int n, const vector<int>& a) {
    // TODO: Implement solution
    return 0;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> apples(n);
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }
    cout << solve(n, apples) << "\n";
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](int n, const vector<int>& a) -> ll {
        return solve(n, a);
    };

    // Sample 1: [3, 2, 7, 4, 1] -> min diff = 1 (groups: {2,7} vs {3,4,1} = 9 vs 8)
    runTest("Sample1", solver, 1LL, 1000, 5, vector<int>{3, 2, 7, 4, 1});

    // All same
    runTest("Sample2", solver, 0LL, 1000, 4, vector<int>{1, 1, 1, 1});

    // Two elements
    runTest("Sample3", solver, 1LL, 1000, 2, vector<int>{1, 2});

    // Single element
    runTest("Sample4", solver, 5LL, 1000, 1, vector<int>{5});

    return 0;
}
#endif
