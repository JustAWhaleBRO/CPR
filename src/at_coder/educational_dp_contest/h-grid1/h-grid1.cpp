// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
void add_help(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int solve(int H, int W, const vector<string>& grid) {
    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (grid[r][c] == '#') continue;

            if (c > 0) {
                add_help(dp[r][c], dp[r][c - 1]);
            }
            if (r > 0) {
                add_help(dp[r][c], dp[r - 1][c]);
            }
        }
    }
    return dp[H - 1][W - 1];
}

#ifndef USE_TEST_HARNESS
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    cout << solve(H, W, grid) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& H, const int& W, const vector<string>& grid) -> ll {
        return solve(H, W, grid);
    };

    // Sample 1: 3x4 grid
    // ...#
    // .#..
    // ....
    // Expected: 3
    runTest("Sample1", solver, 3LL, 500,
        3, 4,
        vector<string>{"...#", ".#..", "...."}
    );

    // Sample 2: 5x2 grid with no paths
    // ..
    // #.
    // ..
    // .#
    // ..
    // Expected: 0
    runTest("Sample2", solver, 0LL, 500,
        5, 2,
        vector<string>{"..", "#.", "..", ".#", ".."}
    );

    // Sample 3: 5x5 grid
    // ..#..
    // .....
    // #...#
    // .....
    // ..#..
    // Expected: 24
    runTest("Sample3", solver, 24LL, 500,
        5, 5,
        vector<string>{"..#..", ".....", "#...#", ".....", "..#.."}
    );

    // Sample 4: 20x20 grid (all empty)
    // Expected: 345263555
    vector<string> grid20x20(20, string(20, '.'));
    runTest("Sample4", solver, 345263555LL, 500,
        20, 20,
        grid20x20
    );

    return 0;
}
#endif
