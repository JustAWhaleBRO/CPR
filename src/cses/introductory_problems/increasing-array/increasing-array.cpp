// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll solve(int n, const vector<int>& arr) {
    // TODO: Implement solution
    return 0;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(n, arr) << "\n";
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](int n, const vector<int>& arr) -> ll {
        return solve(n, arr);
    };

    // Sample 1: [3,2,5,1,7] -> need 5 moves
    runTest("Sample1", solver, 5LL, 1000, 5, vector<int>{3, 2, 5, 1, 7});

    // Additional: already sorted
    runTest("Sample2", solver, 0LL, 1000, 3, vector<int>{1, 2, 3});

    // Additional: decreasing
    runTest("Sample3", solver, 3LL, 1000, 3, vector<int>{3, 2, 1});

    return 0;
}
#endif
