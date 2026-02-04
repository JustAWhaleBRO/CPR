// ==================== LEETCODE SUBMISSION (copy from here) ====================
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check_placement(int n_buckets, int min_distance, vector<int>& position) {
        int buckets_placed = 0;
        int last_placed_position;
        for (int i = 0; i < position.size(); i++) {
            if (i == 0) {
                buckets_placed++;
                last_placed_position = position[i];
            }
            if (position[i] - last_placed_position >= min_distance) {
                buckets_placed++;
                last_placed_position = position[i];
            }
            if (buckets_placed == n_buckets) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int ideal_distance = 1;
        int n = position.size();
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = (position[n - 1] - position[0]) / (m - 1);

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check_placement(m, mid, position)) {
                ideal_distance = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ideal_distance;
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

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);
    Solution sol;

    runTest(
        "Test Case 1",
        [&]() {
            vector<int> position = {1, 2, 3, 4, 7};
            int m = 3;
            return sol.maxDistance(position, m);
        },
        3
    );

    runTest(
        "Test Case 2",
        [&]() {
            vector<int> position = {5, 4, 3, 2, 1, 1000000000};
            int m = 2;
            return sol.maxDistance(position, m);
        },
        999999999
    );

    runTest(
        "Test Case 3",
        [&]() {
            vector<int> position = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int m = 4;
            return sol.maxDistance(position, m);
        },
        3
    );

    return 0;
}
#endif
