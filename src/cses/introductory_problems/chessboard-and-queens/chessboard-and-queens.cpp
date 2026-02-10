// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <string>
using namespace std;

int solve(const string grid[8]) {
    // TODO: Implement solution
    return 0;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string grid[8];
    for (int i = 0; i < 8; i++) {
        cin >> grid[i];
    }
    cout << solve(grid) << "\n";
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"
#include <vector>

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const vector<string>& g) -> int {
        string grid[8];
        for (int i = 0; i < 8; i++) grid[i] = g[i];
        return solve(grid);
    };

    // CSES Example: reserved squares -> 65
    runTest("Sample1", solver, 65, 1000, vector<string>{
        "........",
        "........",
        "..*.....",
        "........",
        "........",
        ".....**.",
        "...*....",
        "........"
    });

    // All free (standard 8-queens problem) -> 92
    runTest("Sample2", solver, 92, 1000, vector<string>{
        "........",
        "........",
        "........",
        "........",
        "........",
        "........",
        "........",
        "........"
    });

    // Blocked first row partial -> queen forced to col 7
    runTest("Sample3", solver, 8, 1000, vector<string>{
        "******.*",
        "........",
        "........",
        "........",
        "........",
        "........",
        "........",
        "........"
    });

    // All blocked -> 0 solutions
    runTest("Sample4", solver, 0, 1000, vector<string>{
        "********",
        "********",
        "********",
        "********",
        "********",
        "********",
        "********",
        "********"
    });

    return 0;
}
#endif
