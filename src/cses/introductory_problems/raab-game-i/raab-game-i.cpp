// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// Raab Game I: Two players each have n cards (1..n).
// Each turn both place a card; higher card scores a point (equal = no point).
// Given n, a, b (scores for player 1 and 2), output a valid game or NO.

void solve(int n, int a, int b) {
    // TODO: Implement solution
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"
#include <sstream>

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](int n, int a, int b) -> string {
        ostringstream oss;
        streambuf* old = cout.rdbuf(oss.rdbuf());
        solve(n, a, b);
        cout.rdbuf(old);
        string result = oss.str();
        if (!result.empty() && result.back() == '\n') result.pop_back();
        return result;
    };

    // CSES Example: n=4, a=1, b=2 -> YES with valid card arrangement
    runTest("Sample1", solver, string("YES\n1 4 3 2\n2 1 3 4"), 1000, 4, 1, 2);

    // CSES Example: n=2, a=0, b=1 -> NO
    runTest("Sample2", solver, string("NO"), 1000, 2, 0, 1);

    // CSES Example: n=3, a=0, b=0 -> YES (all ties)
    runTest("Sample3", solver, string("YES\n1 2 3\n1 2 3"), 1000, 3, 0, 0);

    // CSES Example: n=2, a=1, b=1 -> YES
    runTest("Sample4", solver, string("YES\n1 2\n2 1"), 1000, 2, 1, 1);

    return 0;
}
#endif
