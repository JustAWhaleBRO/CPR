// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using ll = long long;

string solve(ll n) {
    ostringstream oss;
    oss << n;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        oss << " " << n;
    }
    return oss.str();
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](ll n) -> string {
        return solve(n);
    };

    // CSES Example: n=3
    runTest("Sample1", solver, string("3 10 5 16 8 4 2 1"), 1000, 3LL);

    // n=1 -> already 1
    runTest("Sample2", solver, string("1"), 1000, 1LL);

    // n=2 -> 2 1
    runTest("Sample3", solver, string("2 1"), 1000, 2LL);

    // n=4 -> 4 2 1
    runTest("Sample4", solver, string("4 2 1"), 1000, 4LL);

    return 0;
}
#endif
