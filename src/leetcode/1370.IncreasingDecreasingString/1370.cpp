// ==================== LEETCODE SUBMISSION (copy from here) ====================
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        string res = "";
        int n = s.size();
        vector<int> freq(26, 0);
        for (const char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    res += ('a' + i);
                    freq[i]--;
                }
            }

            for (int i = 25; i >= 0; i--) {
                if (freq[i] > 0) {
                    res += ('a' + i);
                    freq[i]--;
                }
            }
        }
        return res;
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
#endif
