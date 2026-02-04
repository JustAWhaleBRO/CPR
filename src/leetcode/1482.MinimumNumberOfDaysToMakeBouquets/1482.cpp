// ==================== LEETCODE SUBMISSION (copy from here) ====================
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMakeBouquets(const vector<int>& bloomDay, int n, int k, int m, int optimal_day, int& bouquets_made) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= optimal_day) {
                count++;
            } else {
                bouquets_made += count / k;
                count = 0;
            }
        }
        bouquets_made += count / k;
        return bouquets_made >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n, optimal_day, max_val, min_val, count, bouquets_made, best_candidate;
        n = bloomDay.size();
        auto [min_int, max_it] = minmax_element(bloomDay.begin(), bloomDay.end());
        max_val = *max_it;
        min_val = *min_int;
        best_candidate = -1;

        if (m * k > n) {
            return -1;
        }

        while (min_val <= max_val) {
            optimal_day = (max_val + min_val) / 2;
            bouquets_made = 0;

            if (canMakeBouquets(bloomDay, n, k, m, optimal_day, bouquets_made)) {
                best_candidate = optimal_day;
                max_val = optimal_day - 1;
            } else {
                min_val = optimal_day + 1;
            }
        }
        return best_candidate;
    }
};

#ifndef USE_TEST_HARNESS
int main() {
    return 0;
}
#endif
// ==================== END LEETCODE SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {
    Solution sol;

    runTest(
        "LC1482 / Case 1",
        [&](vector<int> bloomDay, int m, int k) {
            return sol.minDays(bloomDay, m, k);
        },
        3, 200,
        vector<int>{1,10,3,10,2}, 3, 1
    );

    runTest(
        "LC1482 / Case 2",
        [&](vector<int> bloomDay, int m, int k) {
            return sol.minDays(bloomDay, m, k);
        },
        -1, 200,
        vector<int>{1,10,3,10,2}, 3, 2
    );

    runTest(
        "LC1482 / Case 3",
        [&](vector<int> bloomDay, int m, int k) {
            return sol.minDays(bloomDay, m, k);
        },
        12, 200,
        vector<int>{7,7,7,7,12,7,7}, 2, 3
    );

    runTest(
        "LC1482 / Case 4",
        [&](vector<int> bloomDay, int m, int k) {
            return sol.minDays(bloomDay, m, k);
        },
        1000000000, 200,
        vector<int>{1000000000, 1000000000}, 1, 1
    );

    return 0;
}
#endif

