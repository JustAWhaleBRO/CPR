#include "TestHarness.h"
#include <vector>
#include <numeric>

using namespace std;

// --- LeetCode Solution Class ---
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {
            bool can_reach = false;
            for (int j = i; j <= min(i + nums[i], n - 1); j++) {
                if (dp[j] == true) {
                    can_reach = true;
                    break;
                }
            }
            dp[i] = can_reach;
        }
        return dp[0];
    }
};

// --- End Solution ---

// --- Main Function (Single Vector) ---
int main() {
    Solution sol;

    runTest(
        "Test Case 1",
        [&]() {
            std::vector<int> input = {1,2,0,1,0};
            return sol.canJump(input);
        },
        true,
        10
    );

    runTest(
        "Test Case 2",
        [&]() {
            std::vector<int> input = {1,2,1,0,1};
            return sol.canJump(input);
        },
        false,
        10
    );

    runTest(
        "Test Case 3",
        [&]() {
            std::vector<int> input = {2, 0};
            return sol.canJump(input);
        },
        true,
        10
    );

    return 0;
}
