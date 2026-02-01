#include "TestHarness.h"
#include <stack>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temps_idx;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            const int temp = temperatures[i];

            while (!temps_idx.empty() && temperatures[temps_idx.top()] <= temp) {
                temps_idx.pop();
            }
            if (temps_idx.empty()) {
                res[i] = 0;
            } else {
                res[i] = temps_idx.top() - i;
            }
            temps_idx.push(i);
        }
        return res;
    }
};

// --- Main Function (Single vector, expecting single vector) ---
int main() {
    Solution sol;

    runTest(
    "Test Case 2",
    [&]() {
        vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};
        return sol.dailyTemperatures(temperatures);
    },
    vector<int>{8,1,5,4,3,2,1,1,0,0},
    1
    );

    runTest(
        "Test Case 1",
        [&]() {
            vector<int> temperatures = {30,38,30,36,35,40,28};
            return sol.dailyTemperatures(temperatures);
        },
        vector<int>{1,4,1,2,1,0,0},
        1
    );

    // ---------------------------------------------------------
    // TEST 2: Performance - Worst Case Space (Strictly Increasing)
    // ---------------------------------------------------------
    // Input: [0, 1, 2, 3, ... 99999]
    // Logic: Every element is pushed. In backward pass,
    // stack accumulates (val < top is never true).
    // Expected: [1, 1, 1, ... 0]
    // ---------------------------------------------------------
    {
        const int N = 10000000;
        vector<int> input(N);
        iota(input.begin(), input.end(), 0); // Fill 0 to N-1

        vector<int> expected(N, 1);
        expected.back() = 0; // The last element has no future day

        runTest(
            "Max Constraints: Strictly Increasing (N=100k)",
            [&]() { return sol.dailyTemperatures(input); },
            expected,
            1000
        );
    }

    // ---------------------------------------------------------
    // TEST 3: Performance - Strictly Decreasing
    // ---------------------------------------------------------
    // Input: [99999, ... 2, 1, 0]
    // Logic: No future day is warmer.
    // Expected: [0, 0, ... 0]
    // ---------------------------------------------------------
    {
        const int N = 10000000;
        vector<int> input(N);
        iota(input.rbegin(), input.rend(), 0); // Fill N-1 down to 0

        vector<int> expected(N, 0);

        runTest(
            "Max Constraints: Strictly Decreasing (N=100k)",
            [&]() { return sol.dailyTemperatures(input); },
            expected,
            1000
        );
    }
}