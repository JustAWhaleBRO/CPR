//
// Created by Kiet Van Tran on 28/10/2025.
//
#include "TestHarness.h"
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// --- LeetCode Solution Class ---
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
// --- End Solution ---


// --- Main Function (Test Runner) ---
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