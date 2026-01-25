#include "TestHarness.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;

// --- Solution Implementation Start ---
// Struct to keep tower data organized
struct Tower {
    int x;
    int h;
};

// Predicate function: Can we reach the destination with specific storm height?
bool canReach(int stormHeight, int width, int maxJump, int maxEnergy, const vector<Tower>& towers) {
    // 1. Filter valid stops based on storm height
    // Always include Start (0) and End (width)
    vector<int> validX;
    validX.push_back(0);

    for (const auto& t : towers) {
        if (t.h >= stormHeight) {
            validX.push_back(t.x);
        }
    }
    validX.push_back(width);

    // 2. Run DP to find min energy path
    int n = validX.size();
    // Use long long for costs to prevent overflow during intermediate steps
    vector<long long> dp(n, -1);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        // If this node is unreachable or already exceeds budget, skip
        if (dp[i] == -1 || dp[i] > maxEnergy) continue;

        // Try to jump to subsequent nodes
        for (int j = i + 1; j < n; ++j) {
            long long dist = (long long)validX[j] - validX[i];

            // Optimization: Since X is sorted, if dist exceeds maxJump,
            // no further nodes are reachable from i. Break early.
            if (dist > maxJump) break;

            long long jumpCost = dist * dist;
            long long currentTotal = dp[i] + jumpCost;

            // Update if we found a cheaper path to node j
            if (currentTotal <= maxEnergy) {
                if (dp[j] == -1 || currentTotal < dp[j]) {
                    dp[j] = currentTotal;
                }
            }
        }
    }

    // Check if destination is reachable within budget
    return (dp[n - 1] != -1 && dp[n - 1] <= maxEnergy);
}

int maximumStormHeight(int width, int numTowers, int maxJump, int maxEnergy, vector<int> tower_x, vector<int> tower_h) {
    // 1. Prepare Data
    vector<Tower> towers;
    int maxHeight = 0;
    for(int i=0; i<numTowers; ++i) {
        towers.push_back({tower_x[i], tower_h[i]});
        maxHeight = max(maxHeight, tower_h[i]);
    }

    // Sort by position X (Critical for DP optimization)
    sort(towers.begin(), towers.end(), [](const Tower& a, const Tower& b) {
        return a.x < b.x;
    });

    // Binary Search for the Answer
    int low = 0;
    int high = maxHeight;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canReach(mid, width, maxJump, maxEnergy, towers)) {
            ans = mid;      // This height works, try higher
            low = mid + 1;
        } else {
            high = mid - 1; // Too high, try lower
        }
    }

    return ans;
}
// --- Solution Implementation End ---


// --- Test Suite ---
int main() {
    std::cout << "=== Running Relay Towers Tests ===\n" << std::endl;

    // Test Case 0: Sample Case 0 from problem description
    // width=10, n=2, jump=10, energy=40, x=[4,7], h=[3,5]
    // Path: 0 -> 4 -> 7 -> 10. Cost: 4^2 + 3^2 + 3^2 = 16+9+9 = 34 <= 40.
    // Max height is 3 (limit by tower at x=4 with h=3). If h=4, tower 4 is gone.
    // Can we jump 0->7? Cost 49 > 40? No.
    // So we must use tower 4. Thus max storm height is 3.
    runTest("Sample Case 0", maximumStormHeight, 3, 500,
            10, 2, 10, 40,
            std::vector<int>{4, 7},
            std::vector<int>{3, 5});

    // Test Case 1: Sample Case 1 from problem description
    // width=10, n=2, jump=7, energy=100, x=[4,7], h=[3,5]
    // Energy allows direct jump 0->10 (100 cost), but maxJump=7 prevents it.
    // Path 0->4 (cost 16), 4->7 (cost 9), 7->10 (cost 9). Total 34.
    // If storm=4, tower at 4 (h=3) is buried.
    // Can we do 0->7? Dist=7, Cost=49. Total=49 + 9 = 58 <= 100. YES.
    // So we can skip tower 4. Max height is determined by tower 7 (h=5).
    runTest("Sample Case 1", maximumStormHeight, 5, 500,
            10, 2, 7, 100,
            std::vector<int>{4, 7},
            std::vector<int>{3, 5});

    // -------------------------------------------------------------------------
    // Case 2: "The Bottleneck Bridge"
    // Logic: A single tower exists exactly in the middle.
    // Width=20. Jump=10.
    // Direct jump 0->20 is dist 20 (Impossible, maxJump=10).
    // We MUST use the tower at x=10.
    // Path: 0 -> 10 -> 20. Cost: 10^2 + 10^2 = 100 + 100 = 200.
    // Energy=200. We have exactly enough energy.
    // If this tower is removed (storm > 50), we fail.
    // Expected: 50.
    runTest("Edge: Bottleneck Bridge", maximumStormHeight, 50, 500,
            20, 1, 10, 200,
            std::vector<int>{10},
            std::vector<int>{50});

    // -------------------------------------------------------------------------
    // Case 3: "The Expensive Shortcut vs. The Cheap Detour"
    // Logic: Two possible paths.
    // Path A (High Tower): x=5, h=100. Cost: 5^2 + 5^2 = 50.
    // Path B (Low Tower):  x=4, h=10.  Cost: 4^2 + 6^2 = 16 + 36 = 52.
    // Wait, Path B is MORE expensive in this geometry. Let's invert it.
    //
    // Revised Geometry:
    // Width = 10. MaxJump = 10.
    // Tower A (Low, Cheap):  x=5, h=10.  Cost 5^2 + 5^2 = 50.
    // Tower B (High, Expensive): x=2, h=100. Path: 0->2->10.
    //                            Cost: 2^2 + 8^2 = 4 + 64 = 68.
    //
    // Sub-case A: Energy = 60.
    // We can afford 50 (Low Tower), but NOT 68 (High Tower).
    // If storm > 10, Low Tower is gone. Only High Tower remains.
    // But High Tower is too expensive (68 > 60).
    // So we CANNOT survive a storm > 10.
    // Expected: 10.
    runTest("Edge: Cheap Low / Exp High", maximumStormHeight, 10, 500,
            10, 2, 10, 60,
            std::vector<int>{5, 2},
            std::vector<int>{10, 100});

    // -------------------------------------------------------------------------
    // Case 4: "Stepping Stones (The Chain)"
    // Logic: A sequence of towers 1 unit apart. Jump=1.
    // If ANY tower is removed, the gap becomes 2, which is > maxJump(1).
    // Width=5. Towers at 1, 2, 3, 4. Heights increasing: 10, 20, 30, 40.
    // If storm > 10, tower at 1 is gone. Gap 0->2 is dist 2. FAIL.
    // We are limited by the *weakest link* in the mandatory chain.
    // Expected: 10.
    runTest("Edge: The Weakest Link", maximumStormHeight, 10, 500,
            5, 4, 1, 1000,
            std::vector<int>{1, 2, 3, 4},
            std::vector<int>{10, 20, 30, 40});

    // -------------------------------------------------------------------------
    // Case 5: "The Independent High Road"
    // Logic: A "High Road" of tall towers exists, and a "Low Road" of short towers exists.
    // Width=10, Jump=5.
    // Low Road: 2, 4, 6, 8 (Heights=5). Allows jumps 0->2->4->6->8->10. (Dists=2).
    // High Road: 5 (Height=100). Allows jumps 0->5->10 (Dists=5).
    //
    // Energy is Huge (allow any path).
    // If storm=6: Low road dies. High road (h=100) survives. Can we cross?
    // Yes, via High Road.
    // So the answer is determined by the High Road.
    // Expected: 100.
    runTest("Edge: Independent High Road", maximumStormHeight, 100, 500,
            10, 5, 5, 5000,
            std::vector<int>{2, 4, 6, 8, 5},
            std::vector<int>{5, 5, 5, 5, 100});

    // -------------------------------------------------------------------------
    // Case 6: "Direct Jump Superiority"
    // Logic: We can jump from Start to End directly.
    // Width=10. Jump=10. Energy=100.
    // Direct cost = 100. OK.
    // Tower at 5, h=5. (Cost via tower = 50).
    // If storm > 5, tower is gone.
    // Can we still cross? Yes, direct jump 0->10 cost 100 <= 100.
    // Therefore, the storm height is irrelevant up to the max possible value.
    // The answer should be the height of the tallest tower (or effectively infinite/bound).
    // Based on standard binary search logic (0 to max_h), it returns max_h.
    // Expected: 500 (Height of the tower).
    runTest("Edge: Direct Jump", maximumStormHeight, 500, 500,
            10, 1, 10, 100,
            std::vector<int>{5},
            std::vector<int>{500});

    return 0;
}