// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
using namespace std;
using ll = long long;

char solve(ll k) {
    // TODO: Implement solution
    return '0';
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        cout << solve(k) << "\n";
    }
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](ll k) -> char {
        return solve(k);
    };

    // Sample 1: position 7 -> '7'
    runTest("Sample1", solver, '7', 1000, 7LL);

    // Sample 2: position 19 -> '4' (sequence: 123456789101112131415... pos 19 is '4' in 14)
    runTest("Sample2", solver, '4', 1000, 19LL);

    // Sample 3: position 12 -> '1' (in "11")
    runTest("Sample3", solver, '1', 1000, 12LL);

    return 0;
}
#endif

