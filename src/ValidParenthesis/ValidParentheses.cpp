//
// Created by Kiet Van Tran on 28/10/2025.
//
#include "TestHarness.h"
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;
// --- LeetCode Solution Class ---
class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        std::unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (const char c : str) {
            if (pairs.find(c) != pairs.end()) {
                if (!s.empty() && s.top() == pairs[c]) {
                    s.pop();
                } else {
                    return false;
                }
            } else {
                s.push(c);
            }
        }
        return s.empty();
    }
};



// --- End Solution ---

// --- Main Function (String)---
int main() {
    Solution sol;

    runTest(
        "Test Case 1",
        [&]() {
            string s = "(){}}{";
            return sol.isValid(s);
        },
        false
    );

    runTest(
        "Test Case 2",
        [&]() {
            string s = "([{}])";
            return sol.isValid(s);
        },
        true
    );

    return 0;
}
