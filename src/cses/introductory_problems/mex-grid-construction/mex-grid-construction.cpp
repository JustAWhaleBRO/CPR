// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
using namespace std;

// Mex Grid Construction: Build n x n grid where each cell is the smallest
// nonneg int not appearing to its left in same row or above in same column.

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

    // CSES Example: n=5
    runTest("Sample1", solver, string("0 1 2 3 4\n1 0 3 2 5\n2 3 0 1 6\n3 2 1 0 7\n4 5 6 7 0"), 1000, 5);

    // n=1 -> just 0
    runTest("Sample2", solver, string("0"), 1000, 1);

    // n=2
    runTest("Sample3", solver, string("0 1\n1 0"), 1000, 2);

    // n=3
    runTest("Sample4", solver, string("0 1 2\n1 0 3\n2 3 0"), 1000, 3);

    return 0;
}
#endif

