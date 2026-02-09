// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
using namespace std;
using ll = long long;

string solve(ll a, ll b) {
    // TODO: Implement solution
    return "";
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](ll a, ll b) -> string {
        return solve(a, b);
    };

    // Sample 1: (2, 1) -> YES
    runTest("Sample1", solver, string("YES"), 1000, 2LL, 1LL);

    // Sample 2: (2, 2) -> NO (sum not divisible by 3)
    runTest("Sample2", solver, string("NO"), 1000, 2LL, 2LL);

    // Sample 3: (3, 3) -> YES
    runTest("Sample3", solver, string("YES"), 1000, 3LL, 3LL);

    // (0, 0) -> YES (already empty)
    runTest("Sample4", solver, string("YES"), 1000, 0LL, 0LL);

    return 0;
}
#endif
