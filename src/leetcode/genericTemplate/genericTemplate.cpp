// ==================== LEETCODE SUBMISSION (copy from here) ====================
#include <vector>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    // TODO: Implement your LeetCode solution method here
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};

#ifndef USE_TEST_HARNESS
// LeetCode submission mode
int main() {
    // LeetCode doesn't typically need main()
    return 0;
}
#endif
// ==================== END LEETCODE SUBMISSION ====================

#ifdef USE_TEST_HARNESS
// Test harness mode - for local testing
#include "TestHarness.h"

int main() {
    Solution sol;

    // Pattern 1: Single vector input, vector output
    runTest(
        "Test Case 1",
        [&]() {
            vector<int> input = {1, 2, 3, 4};
            return sol.runningSum(input);
        },
        vector<int>{1, 3, 6, 10}
    );

    // Pattern 2: Another test case
    runTest(
        "Test Case 2",
        [&]() {
            vector<int> input = {1, 1, 1, 1, 1};
            return sol.runningSum(input);
        },
        vector<int>{1, 2, 3, 4, 5}
    );

    return 0;
}
#endif
