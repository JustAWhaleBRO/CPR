//
// Created by Kiet Van Tran on 28/10/2025.
//
#include "TestHarness.h"
#include <vector>
#include <numeric>

// --- LeetCode Solution Class ---
class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};
// --- End Solution ---

// --- Main Function (Single Vector and two integers) ---
int main() {
    Solution sol;

    runTest(
        "Test Case 1",
        [&](std::vector<int> bloomDay, int m, int k) {
            return sol.minDays(bloomDay, m, k);
        },
        /* expected */ 3,
        /* time ms */ 500,
        std::vector<int>{1,10,3,10,2}, 3, 1
    );
}

// --- Main Function (Single vector, expecting single vector) ---
int main() {
    Solution sol;

    runTest(
        "Test Case 1",
        [&]() {
            std::vector<int> temperatures = {1, 2, 3, 4, 7};
            return sol.dailyTemperatures(temperatures);
        },
        std::vector<int>{1,4,1,2,1,0,0}
    );
}

// --- Main Function (vector and one integer) ---
int main() {
    Solution sol;

    // Call runTest WITHOUT <int>
    runTest(
        "Test Case 1",
        [&]() { // Compiler deduces 'Func'
            std::vector<int> position = {1, 2, 3, 4, 7};
            int m = 3;
            return sol.maxDistance(position, m);
        },
        3 // Compiler deduces 'ExpectedType' as int
    );

    // Call runTest WITHOUT <int>
    runTest(
        "Test Case 2",
        [&]() { // Compiler deduces 'Func'
            std::vector<int> position = {5, 4, 3, 2, 1, 1000000000};
            int m = 2;
            return sol.maxDistance(position, m);
        },
        999999999 // Compiler deduces 'ExpectedType' as int
    );

    // Call runTest WITHOUT <int>
    runTest(
        "Test Case 3",
        [&]() { // Compiler deduces 'Func'
            std::vector<int> position = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int m = 4;
            return sol.maxDistance(position, m);
        },
        3 // Compiler deduces 'ExpectedType' as int
    );

    return 0;
}

// --- Main Function (Single Vector) ---
int main() {
    Solution sol;

    runTest(
        "Test Case 1",
        [&]() {
            std::vector<int> input = {1, 2, 3, 4};
            return sol.runningSum(input);
        },
        std::vector<int>{1, 3, 6, 10}
    );

    runTest(
        "Test Case 2",
        [&]() {
            std::vector<int> input = {1, 1, 1, 1, 1};
            return sol.runningSum(input);
        },
        std::vector<int>{1, 2, 3, 4, 5}
    );

    return 0;
}

// --- Main Function (Double Vector) ---
int main() {
    Solution sol;

    runTest(
        "Test Case 1",
        [&]() {
            vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
            int sr = 1, sc = 1, color = 2;
            return sol.floodFill(image, sr, sc, color);
        },
        vector<vector<int>>{{2,2,2},{2,2,0},{2,0,1}}
    );

    runTest(
        "Test Case 2",
        [&]() {
            vector<vector<int>> image = {{0,0,0},{0,0,0}};
            int sr = 0, sc = 0, color = 0;
            return sol.floodFill(image, sr, sc, color);
        },
        vector<vector<int>>{{0,0,0},{0,0,0}}
    );

    return 0;
}

// --- Main Function (String)---
int main() {
    Solution sol;

    runTest(
        "Test Case 1",
        [&]() {
            string s = "aaaabbbbcccc";
            return sol.sortString(s);
        },
        "abccbaabccba"
    );

    runTest(
        "Test Case 2",
        [&]() {
            string s = "rat";
            return sol.sortString(s);
        },
        "art"
    );

    return 0;
}
