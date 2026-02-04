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

    // =========================================================================
    // PATTERN 1: Single vector input → vector output
    // =========================================================================
    runTest(
        "Pattern 1: Vector → Vector",
        [&]() {
            vector<int> input = {1, 2, 3, 4};
            return sol.runningSum(input);
        },
        vector<int>{1, 3, 6, 10}
    );

    // =========================================================================
    // PATTERN 2: Vector + single parameter → scalar output
    // =========================================================================
    // runTest(
    //     "Pattern 2: Vector + Int → Int",
    //     [&]() {
    //         vector<int> nums = {1, 2, 3, 4, 5};
    //         int target = 5;
    //         return sol.search(nums, target);
    //     },
    //     2  // Expected index
    // );

    // =========================================================================
    // PATTERN 3: Vector + multiple parameters → scalar output
    // =========================================================================
    // runTest(
    //     "Pattern 3: Vector + Multiple Params → Int",
    //     [&]() {
    //         vector<int> bloomDay = {1, 10, 3, 10, 2};
    //         int m = 3;
    //         int k = 1;
    //         return sol.minDays(bloomDay, m, k);
    //     },
    //     3,    // Expected result
    //     500   // Time limit (ms)
    // );

    // =========================================================================
    // PATTERN 4: 2D vector input → 2D vector output
    // =========================================================================
    // runTest(
    //     "Pattern 4: 2D Vector → 2D Vector",
    //     [&]() {
    //         vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    //         int sr = 1, sc = 1, color = 2;
    //         return sol.floodFill(image, sr, sc, color);
    //     },
    //     vector<vector<int>>{{2, 2, 2}, {2, 2, 0}, {2, 0, 1}},
    //     1000
    // );

    // =========================================================================
    // PATTERN 5: String input → string output
    // =========================================================================
    // runTest(
    //     "Pattern 5: String → String",
    //     [&]() {
    //         string s = "aaaabbbbcccc";
    //         return sol.sortString(s);
    //     },
    //     "abccbaabccba"
    // );

    // =========================================================================
    // PATTERN 6: String input → bool output
    // =========================================================================
    // runTest(
    //     "Pattern 6: String → Bool",
    //     [&]() {
    //         string s = "()[]{}";
    //         return sol.isValid(s);
    //     },
    //     true
    // );

    // =========================================================================
    // PATTERN 7: Multiple vectors → scalar output
    // =========================================================================
    // runTest(
    //     "Pattern 7: Two Vectors → Int",
    //     [&]() {
    //         vector<int> nums1 = {1, 2};
    //         vector<int> nums2 = {3, 4};
    //         return sol.findMedianSortedArrays(nums1, nums2);
    //     },
    //     2.5
    // );

    // =========================================================================
    // PATTERN 8: Pass by reference with lambda capture
    // =========================================================================
    // runTest(
    //     "Pattern 8: Lambda with Capture",
    //     [&](vector<int> position, int m) {
    //         return sol.maxDistance(position, m);
    //     },
    //     3,    // Expected result
    //     500,  // Time limit
    //     vector<int>{1, 2, 3, 4, 7}, 3  // Arguments
    // );

    // =========================================================================
    // PATTERN 9: Performance test with large input
    // =========================================================================
    // {
    //     const int N = 100000;
    //     vector<int> largeInput(N);
    //     iota(largeInput.begin(), largeInput.end(), 0);
    //
    //     vector<int> expected(N, 1);
    //     expected.back() = 0;
    //
    //     runTest(
    //         "Pattern 9: Large Input Performance",
    //         [&]() { return sol.dailyTemperatures(largeInput); },
    //         expected,
    //         1000  // Time limit for performance test
    //     );
    // }

    // =========================================================================
    // PATTERN 10: TreeNode* input (LeetCode tree problems)
    // =========================================================================
    // struct TreeNode {
    //     int val;
    //     TreeNode *left, *right;
    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // };
    //
    // runTest(
    //     "Pattern 10: TreeNode → Int",
    //     [&]() {
    //         TreeNode* root = new TreeNode(1);
    //         root->left = new TreeNode(2);
    //         root->right = new TreeNode(3);
    //         return sol.maxDepth(root);
    //     },
    //     2
    // );

    // =========================================================================
    // PATTERN 11: ListNode* input (LeetCode linked list problems)
    // =========================================================================
    // struct ListNode {
    //     int val;
    //     ListNode *next;
    //     ListNode(int x) : val(x), next(nullptr) {}
    // };
    //
    // runTest(
    //     "Pattern 11: ListNode → ListNode",
    //     [&]() {
    //         ListNode* head = new ListNode(1);
    //         head->next = new ListNode(2);
    //         head->next->next = new ListNode(3);
    //         return sol.reverseList(head);
    //     },
    //     // Expected: ListNode with values [3, 2, 1]
    //     // Note: Implement custom comparison for ListNode*
    // );

    return 0;
}
#endif
