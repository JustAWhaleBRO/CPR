// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
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

    // Sample 1: n=2
    runTest("Sample1", solver, string("3\n1 3\n1 2\n3 2\n2 1\n2 3\n1 3"), 1000, 2);

    // n=1
    runTest("Sample2", solver, string("1\n1 3"), 1000, 1);

    return 0;
}
#endif
