#include "TestHarness.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Computes the cumulative capacity available up to generation x.
 *
 * Pattern:
 * Gen 1: +1 (Total 1)
 * Gen 2: +2 (Total 3)
 * Gen 3: +1 (Total 4)
 * Gen 4: +2 (Total 6)
 *
 * @param x The generation number.
 * @return Total capacity (sum of neurons that can be added).
 */
long GetCapacity(long x) {
    // Odd generations count: ceil(x/2)
    long odd_count = (x + 1) / 2;
    // Even generations count: floor(x/2)
    long even_count = x / 2;
    return odd_count * 1 + even_count * 2;
}

/**
 * @brief Determines if the target configuration is feasible within x generations.
 *
 * @param x The generation limit to test.
 * @param sum_needed Total sum of differences required.
 * @param odd_needed Count of layers requiring an odd increment.
 * @return true if feasible, false otherwise.
 */
bool IsFeasible(long x, long sum_needed, long odd_needed) {
    long odd_available = (x + 1) / 2;
    long total_capacity = GetCapacity(x);

    // Constraint 1: Hard Parity Limit
    // We cannot fix N odd errors if we have fewer than N odd coins.
    if (odd_available < odd_needed) {
        return false;
    }

    // Constraint 2: Sum with Parity Efficiency
    // If we have "spare" odd coins (available - needed), they must be paired
    // to form 2s (1+1=2) to contribute efficiently to the sum.
    // If the number of spare odds is Odd, one '1' is left floating.
    // That floating '1' cannot be used to fill an even gap (it would break parity).
    // Thus, we effectively lose 1 unit of capacity.
    long spare_odd = odd_available - odd_needed;
    if (spare_odd % 2 != 0) {
        total_capacity -= 1;
    }

    return total_capacity >= sum_needed;
}

/**
 * @brief Binary search solver for a fixed Target value.
 *
 * @param layer The input array of neurons.
 * @param target The specific target value we are testing.
 * @return The minimum generations required for this specific target.
 */
long SolveForTarget(const std::vector<int>& layer, long target) {
    long sum_needed = 0;
    long odd_needed = 0;

    for (int val : layer) {
        long diff = target - val;
        sum_needed += diff;
        if (diff % 2 != 0) {
            odd_needed++;
        }
    }

    // Binary Search Range: [0, 2e14]
    // 2e14 is sufficient as max(layer) <= 10^9 and n <= 10^5
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
 *
 * @param layer Vector containing the number of neurons in each layer.
 * @return The minimum generation number.
 */
long findMinGeneration(std::vector<int> layer) {
    if (layer.empty()) return 0;

    int max_val = layer[0];
    for (int val : layer) {
        if (val > max_val) max_val = val;
    }

    // We calculate the cost for Target = Max AND Target = Max + 1.
    // The latter often resolves parity bottlenecks (High Parity/Low Sum -> Low Parity/High Sum).
    long ans1 = SolveForTarget(layer, max_val);
    long ans2 = SolveForTarget(layer, max_val + 1);

    return static_cast<long>(std::min(ans1, ans2));
}

// -----------------------------------------------------------------------------
// Test Runner
// -----------------------------------------------------------------------------

int main() {
    std::cout << "=== Neural Network Generation Optimizer Tests ===\n\n";

    // ---------------------------------------------------------
    // Case 1: From Image 1 (Sample Case 0)
    // Input: n=3, layer=[3, 3, 6]
    // Explanation: Max=6. To make [3,3,6] -> [6,6,6] takes 4 gens.
    // ---------------------------------------------------------
    std::vector<int> case0 = {3, 3, 6};
    runTest("Sample Case 0 (Image 1)", findMinGeneration, 4L, 100, case0);

    // ---------------------------------------------------------
    // Case 2: From Image 2 (Sample Case 1)
    // Input: n=4, layer=[2, 2, 3, 5]
    // Explanation: Max=5. Optimal is Target=5. Result 6.
    // ---------------------------------------------------------
    std::vector<int> case1 = {2, 2, 3, 5};
    runTest("Sample Case 1 (Image 2)", findMinGeneration, 6L, 100, case1);

    // ---------------------------------------------------------
    // Case 3: From User's Failing Test Case (Image 3)
    // Input: n=5, layer=[1, 1, 1, 1, 2]
    // Explanation:
    // - Target=2 requires fixing 4 odd numbers. Impossible in 6 gens (only 3 odd slots).
    // - Target=3 requires fixing 1 odd number. Possible in 6 gens.
    // Expected Output: 6
    // ---------------------------------------------------------
    std::vector<int> case2 = {1, 1, 1, 1, 2};
    runTest("Parity Trap Case (User Input)", findMinGeneration, 6L, 100, case2);

    return 0;
}