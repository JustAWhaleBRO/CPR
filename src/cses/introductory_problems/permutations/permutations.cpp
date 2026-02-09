// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
using namespace std;

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

    // Sample 1: n=5 -> valid permutation (2 4 1 3 5 is one option)
    runTest("Sample1", solver, string("2 4 1 3 5"), 1000, 5);

    // Sample 2: n=3 -> NO SOLUTION
    runTest("Sample2", solver, string("NO SOLUTION"), 1000, 3);

    // n=1 -> just 1
    runTest("Sample3", solver, string("1"), 1000, 1);

    // n=4 -> valid
    runTest("Sample4", solver, string("2 4 1 3"), 1000, 4);

    return 0;
}
#endif
