#include <iostream>
#include <vector>
#include <algorithm>
#include "TestHarness.h"

using namespace std;
/**
 * Checks if a team of size k is possible respecting the original order.
 *
 * Constraint: The team must be a subsequence of the original developers.
 * Developer i (0-indexed) has skill level i.
 * If developer i is the j-th member of the team (1-based rank within the team):
 * 1. They need j-1 lower skilled members:  j-1 <= lowerSkill[i]  => j <= lowerSkill[i] + 1
 * 2. They need k-j higher skilled members: k-j <= higherSkill[i] => j >= k - higherSkill[i]
 *
 * Logic:
 * We iterate through the developers in their original order (0 to n-1).
 * We maintain a counter `current_rank_needed` starting at 1.
 * If the current developer can satisfy the constraints for `current_rank_needed`
 * in a team of size `k`, we greedily pick them and increment `current_rank_needed`.
 *
 * Because the pool of candidates for rank `r+1` is always a subset of the developers
 * appearing after rank `r`, picking the earliest valid candidate for rank `r` is
 * always optimal.
 */
bool can_form_team(int n, const std::vector<int>& lower_skill, const std::vector<int>& higher_skill, int k) {
    if (k == 0) return true;
    
    int current_rank_needed = 1;

    // Iterate through developers by increasing skill level (inherent order 0 to n-1)
    for (int i = 0; i < n; ++i) {
        // Calculate the valid rank range [L, R] this developer can accept
        int L = std::max(1, k - higher_skill[i]);
        int R = std::min(k, lower_skill[i] + 1);

        // If this developer can be the 'current_rank_needed'-th person:
        if (current_rank_needed >= L && current_rank_needed <= R) {
            current_rank_needed++;
            
            // If we have filled all k positions, success!
            if (current_rank_needed > k) {
                return true;
            }
        }
    }

    return false;
}

int getOptimalTeamSize(std::vector<int> lowerSkill, std::vector<int> higherSkill) {
    int n = lowerSkill.size();
    
    int l = 0;
    int r = n;
    int ans = 0;

    // Binary search on the Answer
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        if (can_form_team(n, lowerSkill, higherSkill, mid)) {
            ans = mid;      // Store valid answer
            l = mid + 1;    // Try for a bigger team
        } else {
            r = mid - 1;    // Too big, try smaller
        }
    }

    return ans;
}

// ============================================================================
// Test Execution
// ============================================================================

int main() {
    std::cout << "=== Running Hackathon Team Optimization Tests ===\n" << std::endl;

    // ------------------------------------------------------------------------
    // Test Case 1: Sample Input 0 (from image_63a70f.png)
    // Expected: 3
    // ------------------------------------------------------------------------
    std::vector<int> l1 = {0, 4, 2, 3, 3};
    std::vector<int> h1 = {0, 1, 3, 2, 4};
    runTest("Sample Input 0", getOptimalTeamSize, 3, 500, l1, h1);

    // ------------------------------------------------------------------------
    // Test Case 2: Sample Input 1 (from image_63a709.png / image_63a2eb.png)
    // Expected: 4
    // ------------------------------------------------------------------------
    std::vector<int> l2 = {3, 4, 2, 1, 2, 5};
    std::vector<int> h2 = {1, 3, 4, 5, 3, 5};
    runTest("Sample Input 1", getOptimalTeamSize, 4, 500, l2, h2);

    // ------------------------------------------------------------------------
    // Test Case 3: Specific Failure Case (from image_63a6ed.png)
    // Expected: 5
    // ------------------------------------------------------------------------
    std::vector<int> l3 = {3, 2, 3, 5, 5, 1};
    std::vector<int> h3 = {4, 3, 2, 5, 3, 2};
    runTest("Failure Case (Exp 5)", getOptimalTeamSize, 5, 500, l3, h3);

    return 0;
}