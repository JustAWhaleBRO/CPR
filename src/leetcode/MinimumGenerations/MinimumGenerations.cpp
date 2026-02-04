// ==================== LEETCODE SUBMISSION (copy from here) ====================
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * @brief Computes the cumulative capacity available up to generation x.
 */
long GetCapacity(long x) {
    long odd_count = (x + 1) / 2;
    long even_count = x / 2;
    return odd_count * 1 + even_count * 2;
}

/**
 * @brief Determines if the target configuration is feasible within x generations.
 */
bool IsFeasible(long x, long sum_needed, long odd_needed) {
    long odd_available = (x + 1) / 2;
    long total_capacity = GetCapacity(x);

    if (odd_available < odd_needed) {
        return false;
    }

    long spare_odd = odd_available - odd_needed;
    if (spare_odd % 2 != 0) {
        total_capacity -= 1;
    }

    return total_capacity >= sum_needed;
}

/**
 * @brief Binary search solver for a fixed Target value.
 */
long SolveForTarget(const vector<int>& layer, long target) {
    long sum_needed = 0;
    long odd_needed = 0;

    for (int val : layer) {
        long diff = target - val;
        sum_needed += diff;
        if (diff % 2 != 0) {
            odd_needed++;
        }
    }

    long low = 0, high = 2 * sum_needed;
    long ans = high;

    while (low <= high) {
        long mid = low + (high - low) / 2;
        if (IsFeasible(mid, sum_needed, odd_needed)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

/**
 * @brief Main API function to find the minimum generations.
 */
long findMinGeneration(vector<int> layer) {
    if (layer.empty()) return 0;

    int max_val = layer[0];
    for (int val : layer) {
        if (val > max_val) max_val = val;
    }

    long ans1 = SolveForTarget(layer, max_val);
    long ans2 = SolveForTarget(layer, max_val + 1);

    return static_cast<long>(min(ans1, ans2));
}

#ifndef USE_TEST_HARNESS
int main() {
    return 0;
}
#endif
// ==================== END LEETCODE SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"
#include <iostream>

int main() {
    cout << "=== Neural Network Generation Optimizer Tests ===\n\n";

    vector<int> case0 = {3, 3, 6};
    runTest("Sample Case 0 (Image 1)", findMinGeneration, 4L, 100, case0);

    vector<int> case1 = {2, 2, 3, 5};
    runTest("Sample Case 1 (Image 2)", findMinGeneration, 6L, 100, case1);

    vector<int> case2 = {1, 1, 1, 1, 2};
    runTest("Parity Trap Case (User Input)", findMinGeneration, 6L, 100, case2);

    return 0;
}
#endif
