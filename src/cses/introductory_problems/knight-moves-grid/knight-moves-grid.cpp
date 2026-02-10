// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Knight Moves Grid: On n x n board, print min moves to reach (0,0) for each square.

void solve(int n) {
    // TODO: Implement solution
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

    // CSES Example: n=8
    runTest("Sample1", solver, string(
        "0 3 2 3 2 3 4 5\n"
        "3 4 1 2 3 4 3 4\n"
        "2 1 4 3 2 3 4 5\n"
        "3 2 3 2 3 4 3 4\n"
        "2 3 2 3 4 3 4 5\n"
        "3 4 3 4 3 4 5 4\n"
        "4 3 4 3 4 5 4 5\n"
        "5 4 5 4 5 4 5 6"), 5000, 8);

    // n=4 (minimum valid)
    runTest("Sample2", solver, string(
        "0 3 2 5\n"
        "3 4 1 2\n"
        "2 1 4 3\n"
        "5 2 3 2"), 1000, 4);

    // n=5
    runTest("Sample3", solver, string(
        "0 3 2 3 2\n"
        "3 4 1 2 3\n"
        "2 1 4 3 2\n"
        "3 2 3 2 3\n"
        "2 3 2 3 4"), 1000, 5);

    // n=6
    runTest("Sample4", solver, string(
        "0 3 2 3 2 3\n"
        "3 4 1 2 3 4\n"
        "2 1 4 3 2 3\n"
        "3 2 3 2 3 4\n"
        "2 3 2 3 4 3\n"
        "3 4 3 4 3 4"), 1000, 6);

    return 0;
}
#endif

