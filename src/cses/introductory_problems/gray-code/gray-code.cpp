// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <string>
#include <format>
#include <vector>
#include "Debug.h"
using namespace std;

vector<string> res;
vector<string> tree_lines;  // For debug: collect tree structure

void dfs(int curr, int level, int last_level, bool invert_order, string prefix = "") {
    string binary = format("{:0{}b}", curr, last_level);

    if (level == last_level) {
        tree_lines.push_back(prefix + "└─ LEAF: " + binary);
        res.emplace_back(binary);
        return;
    }

    int bit_pos = last_level - 1 - level;
    tree_lines.push_back(prefix + "├─ [" + to_string(level) + "] curr=" + binary + " invert=" + (invert_order ? "T" : "F"));

    if (!invert_order) {
        dfs(curr, level + 1, last_level, false, prefix + "│  ");
        dfs(curr | (1 << bit_pos), level + 1, last_level, true, prefix + "│  ");
    } else {
        dfs(curr | (1 << bit_pos), level + 1, last_level, false, prefix + "│  ");
        dfs(curr, level + 1, last_level, true, prefix + "│  ");
    }
}

void solve(int n) {
    res.clear();
    tree_lines.clear();
    dfs(0, 0, n, false);

    // Print tree structure for debug
    dbg_section("DFS Tree");
    if (isDebugEnabled()) {
        for (const auto& line : tree_lines) {
            cerr << line << endl;
        }
    }
    dbg_section("Result");
    dbg(res);

    for (const string& code : res) {
        cout << code << endl;
    }
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    solve(n);
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"
#include <sstream>

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](int n) -> string {
        ostringstream oss;
        streambuf* old = cout.rdbuf(oss.rdbuf());
        solve(n);
        cout.rdbuf(old);
        string result = oss.str();
        if (!result.empty() && result.back() == '\n') result.pop_back();
        return result;
    };

    // Sample 1: n=2
    runTest("Sample1", solver, string("00\n01\n11\n10"), 1000, 2);

    // n=1
    runTest("Sample2", solver, string("0\n1"), 1000, 1);

    // n=3
    runTest("Sample3", solver, string("000\n001\n011\n010\n110\n111\n101\n100"), 1000, 3);

    // n=4 -> 16 lines
    runTest("Sample4", solver, string("0000\n0001\n0011\n0010\n0110\n0111\n0101\n0100\n1100\n1101\n1111\n1110\n1010\n1011\n1001\n1000"), 1000, 4);

    return 0;
}
#endif
