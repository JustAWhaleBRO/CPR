// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct State {
    int len;
    int prev_row;
    int prev_col;

    State(int length, int row, int col) : len(length), prev_row(row), prev_col(col) {}
};

string solve(const string &s, const string &t) {
    int s_len = s.size(), t_len = t.size();
    vector<vector<State>> dp(s_len + 1, vector<State>(t_len + 1, {0, 0, 0}));
    // dp[i][j] is the max total length so far

    for (int i = 1; i <= s_len; i++) {
        for (int j = 1; j <= t_len; j++) {
            State *new_state = &dp[i][j];

            if (s[i - 1] == t[j - 1]) {
                State *old_state = &dp[i - 1][j - 1];
                new_state->len = old_state->len + 1;
                new_state->prev_row = i - 1;
                new_state->prev_col = j - 1;

            } else {
                State *from_top = &dp[i - 1][j];
                State *from_left = &dp[i][j - 1];

                if (from_top->len >= from_left->len) {
                    new_state->len = from_top->len;
                    new_state->prev_row = i - 1;
                    new_state->prev_col = j;
                } else {
                    new_state->len = from_left->len;
                    new_state->prev_row = i;
                    new_state->prev_col = j - 1;

                }
            }
        }
    }

    string res = "";
    int r = s_len;
    int c = t_len;
    while (dp[r][c].len > 0) {
        int prev_r = dp[r][c].prev_row;
        int prev_c = dp[r][c].prev_col;

        if (prev_r < r && prev_c < c) {
            res.push_back(s[r - 1]);
        }
        r = prev_r;
        c = prev_c;
    }
    reverse(res.begin(), res.end());
    return res;
}

#ifndef USE_TEST_HARNESS
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const string& s, const string& t) -> string {
        return solve(s, t);
    };

    // Sample 1: "axyb", "abyxb" → Expected: "axb" or "ayb"
    runTest("Sample1", solver, string("axb"), 500,
        string("axyb"),
        string("abyxb")
    );

    // Sample 2: "aa", "xayaz" → Expected: "aa"
    runTest("Sample2", solver, string("aa"), 500,
        string("aa"),
        string("xayaz")
    );

    // Sample 3: "a", "z" → Expected: "" (empty string)
    runTest("Sample3", solver, string(""), 500,
        string("a"),
        string("z")
    );

    // Sample 4: "abracadabra", "avadakedavra" → Expected: "aaadara"
    runTest("Sample4", solver, string("aaadara"), 500,
        string("abracadabra"),
        string("avadakedavra")
    );

    return 0;
}
#endif
