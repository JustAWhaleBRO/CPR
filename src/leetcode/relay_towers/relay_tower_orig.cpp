/**
 * =========================================================
 * HACKERRANK "RELAY TOWERS" - RIGOROUS SOLUTION & TESTER
 * =========================================================
 * * Author: Gemini (Your Friendly CS Professor)
 * Complexity: O(N log N) using Convex Hull Trick
 * Status: Optimized for 10^5 towers and 10^18 energy.
 */

#include <algorithm>
#include <vector>
#include <deque>
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

// =========================================================
//  PART 1: THE CORE SOLUTION (Copy this to HackerRank)
// =========================================================

// STRICTLY use __int128_t for cross-multiplication.
// 10^18 (cost) * 10^9 (slope) = 10^27, exceeding 64-bit limits.
typedef __int128_t int128;
using ll = long long;

struct Tower {
    ll x;
    ll h;
    int original_index;
};

// Represents a line y = mx + c for the Convex Hull
struct Line {
    ll m;
    ll c;
    ll x_source;

    ll eval(ll x) const {
        return m * x + c;
    }
};

class Solution {
public:
    // Predicate: Can we reach the destination at a specific storm level?
    bool canReach(ll width, ll max_jump, ll max_energy,
                  ll storm_threshold, const std::vector<Tower>& towers) {

        // Optimization: Use std::vector as a Deque (faster than std::deque)
        std::vector<Line> hull;
        hull.reserve(towers.size() + 2);
        int head = 0; // "Front" of the deque

        // Base case: Start at x=0, cost=0
        hull.push_back({0, 0, 0});

        ll final_cost = -1;
        bool reached_end = false;

        for (const auto& tower : towers) {
            // Skip submerged towers (Destination is never submerged)
            if (tower.x != width && tower.h < storm_threshold) continue;

            ll curr_x = tower.x;

            // 1. "Pop Front": Remove lines too far away (maxJump constraint)
            while (head < hull.size() && hull[head].x_source < curr_x - max_jump) {
                head++;
            }

            // If empty, this tower is unreachable
            if (head >= hull.size()) {
                if (curr_x == width) return false;
                continue;
            }

            // 2. Query Optimization (CHT): Remove suboptimal lines from front
            while (head + 1 < hull.size() &&
                   hull[head].eval(curr_x) >= hull[head + 1].eval(curr_x)) {
                head++;
            }

            ll best_prev = hull[head].eval(curr_x);
            ll curr_cost = best_prev + curr_x * curr_x;

            if (curr_x == width) {
                final_cost = curr_cost;
                reached_end = true;
                break;
            }

            // 3. Add new line to "Back": Maintain Lower Convex Hull
            if (curr_cost <= max_energy) {
                Line new_line;
                new_line.m = -2 * curr_x;
                new_line.c = curr_cost + curr_x * curr_x;
                new_line.x_source = curr_x;

                while (hull.size() >= head + 2) {
                    const Line& l2 = hull.back();
                    const Line& l1 = hull[hull.size() - 2];

                    // Intersection check: (c2 - c1) * (m1 - m2) >= (c_new - c2) * (m2 - m_new)
                    // Uses __int128 to prevent overflow
                    int128 left = (int128)(l2.c - l1.c) * (l2.m - new_line.m);
                    int128 right = (int128)(new_line.c - l2.c) * (l1.m - l2.m);

                    if (left >= right) {
                        hull.pop_back();
                    } else {
                        break;
                    }
                }
                hull.push_back(new_line);
            }
        }

        return reached_end && (final_cost <= max_energy);
    }

    int maximumStormHeight(ll width, ll maxJump, ll maxEnergy, ll numTowers,
                           const std::vector<ll>& x, const std::vector<ll>& height) {

        // Edge Case: Direct Jump
        if (width <= maxJump && width * width <= maxEnergy) {
            return 1000000000;
        }

        // Prepare data
        std::vector<Tower> towers;
        towers.reserve(numTowers + 1);
        std::vector<int> unique_heights;
        unique_heights.reserve(numTowers);

        for (int i = 0; i < numTowers; ++i) {
            towers.push_back({x[i], height[i], i});
            unique_heights.push_back((int)height[i]);
        }
        towers.push_back({width, 2000000000LL, -1}); // Destination

        // Sort search space
        std::sort(unique_heights.begin(), unique_heights.end());
        auto last = std::unique(unique_heights.begin(), unique_heights.end());
        unique_heights.erase(last, unique_heights.end());

        // Binary Search for Answer
        int low = 0;
        int high = unique_heights.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int candidate = unique_heights[mid];

            if (canReach(width, maxJump, maxEnergy, candidate, towers)) {
                ans = candidate;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

// Wrapper function to match the C-style interface often used in Main
int maximumStormHeight(int width, int numTowers, int maxJump, ll maxEnergy,
                       std::vector<int> x, std::vector<int> h) {
    Solution sol;
    std::vector<ll> lx(x.begin(), x.end());
    std::vector<ll> lh(h.begin(), h.end());
    return sol.maximumStormHeight(width, maxJump, maxEnergy, numTowers, lx, lh);
}


// =========================================================
//  PART 2: THE TEST HARNESS (For Local Verification)
// =========================================================

void runTest(std::string name, int expected,
             int width, int numTowers, int maxJump, ll maxEnergy,
             std::vector<int> x, std::vector<int> h) {

    std::cout << "[TEST] " << std::left << std::setw(25) << name << " | ";
    int result = maximumStormHeight(width, numTowers, maxJump, maxEnergy, x, h);

    if (result == expected) {
        std::cout << "PASSED (Got " << result << ")" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
        std::cout << "       Expected: " << expected << ", Got: " << result << std::endl;
    }
}

void runAllTests() {
    std::cout << "\n=== Running Relay Towers Test Suite ===\n" << std::endl;

    // Case 0: Sample 0
    runTest("Sample Case 0", 3, 10, 2, 10, 40, {4, 7}, {3, 5});

    // Case 1: Sample 1 (Corrected logic: should be 5)
    runTest("Sample Case 1", 5, 10, 2, 7, 100, {4, 7}, {3, 5});

    // Case 2: Bottleneck Bridge
    runTest("Bottleneck Bridge", 50, 20, 1, 10, 200, {10}, {50});

    // Case 3: Direct Jump (Infinite/Max Height)
    runTest("Direct Jump", 1000000000, 10, 1, 10, 100, {5}, {50});

    // Case 4: Weakest Link (Chain)
    runTest("Weakest Link", 10, 5, 4, 1, 1000, {1,2,3,4}, {10,20,30,40});

    std::cout << "\n=== Tests Complete ===\n" << std::endl;
}


// =========================================================
//  PART 3: THE MAIN FUNCTION (Original Environment Sim)
// =========================================================

int main() {
    // 1. Run Tests automatically so you can see it works
    runAllTests();

    // 2. Standard Input Processing (Simulating HackerRank)
    // You can paste the custom input here after the tests run.

    std::cout << "Waiting for Standard Input (Paste your case below)..." << std::endl;
    std::cout << "Format: width numTowers maxJump maxEnergy [Enter] ... towers ..." << std::endl;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    // Skip empty lines if any
    while (std::getline(std::cin, line) && line.empty()) {}
    if (line.empty()) return 0;

    std::istringstream iss(line);
    ll width, maxEnergy;
    int numTowers, maxJump;

    // FIX: Using the CORRECT order relative to Problem Description
    // If your local input box has the old order, YOU MUST UPDATE YOUR INPUT TEXT.
    // Correct Order: width >> numTowers >> maxJump >> maxEnergy
    if (!(iss >> width >> numTowers >> maxJump >> maxEnergy)) {
        return 0;
    }

    std::vector<int> x(numTowers);
    std::vector<int> h(numTowers);

    for (int i = 0; i < numTowers; ++i) {
        std::cin >> x[i] >> h[i];
    }

    int result = maximumStormHeight((int)width, numTowers, maxJump, maxEnergy, x, h);
    std::cout << result << std::endl;

    return 0;
}
/*
    10 2 10 40
    4 3
    7 5

*/