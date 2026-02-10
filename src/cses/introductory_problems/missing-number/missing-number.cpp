// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll solve(int n, const vector<int>& nums) {
    ll remainder = (ll) n * (n + 1) / 2;
    for (int num : nums) {
        remainder -= num;
    }
    return remainder;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> nums[i];
    }
    cout << solve(n, nums) << "\n";
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](int n, const vector<int>& nums) -> int {
        return solve(n, nums);
    };

    // CSES Example: n=5, missing 4
    runTest("Sample1", solver, 4, 1000, 5, vector<int>{2, 3, 1, 5});

    // n=2, missing 1
    runTest("Sample2", solver, 1, 1000, 2, vector<int>{2});

    // n=3, missing 3
    runTest("Sample3", solver, 3, 1000, 3, vector<int>{1, 2});

    // n=4, missing 2
    runTest("Sample4", solver, 2, 1000, 4, vector<int>{4, 1, 3});

    return 0;
}
#endif
