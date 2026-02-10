// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Grid Coloring I: Given n x m grid of A/B/C/D, change every cell to a
// different character so no two adjacent cells share the same character.
// Print IMPOSSIBLE if not possible.

void solve(int n, int m, vector<string>& grid) {
    // TODO: Implement solution
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    solve(n, m, grid);
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"
#include <sstream>

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](int n, int m, const vector<string>& g) -> string {
        vector<string> grid = g;
        ostringstream oss;
        streambuf* old = cout.rdbuf(oss.rdbuf());
        solve(n, m, grid);
        cout.rdbuf(old);
        string result = oss.str();
        if (!result.empty() && result.back() == '\n') result.pop_back();
        return result;
    };

    // CSES Example: 3x4
    runTest("Sample1", solver, string("CDCD\nDCDC\nABAB"), 1000,
        3, 4, vector<string>{"AAAA", "BBBB", "CCDD"});

    // 1x1: single cell, just change it
    runTest("Sample2", solver, string("B"), 1000,
        1, 1, vector<string>{"A"});

    // 2x2 grid
    runTest("Sample3", solver, string("BA\nAB"), 1000,
        2, 2, vector<string>{"AB", "BA"});

    // 1x4 row
    runTest("Sample4", solver, string("BABA"), 1000,
        1, 4, vector<string>{"ABAB"});

    return 0;
}
#endif

