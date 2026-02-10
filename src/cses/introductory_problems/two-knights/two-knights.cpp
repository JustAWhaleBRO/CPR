// ==================== CSES SUBMISSION (copy from here) ====================
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;

ll solve(int n) {
    int board_size = n * n;
    ll all_ways = (ll) board_size * (board_size - 1) / 2;

    ll bad_ways = (n - 4) * (n - 4) * 8;
    bad_ways += (n - 4) * 4 * 6;
    bad_ways += (n - 3) * 4 * 4;
    bad_ways += 8 * 3 + 4 * 2;
    bad_ways /= 2;

    return all_ways - bad_ways;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        cout << solve(k) << "\n";
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

    auto solver = [](int n) -> string {
        ostringstream oss;
        for (int k = 1; k <= n; k++) {
            oss << solve(k) << "\n";
        }
        string result = oss.str();
        if (!result.empty() && result.back() == '\n') result.pop_back();
        return result;
    };

    // Sample: n=8
    runTest("Sample1", solver, string("0\n6\n28\n96\n252\n550\n1056\n1848"), 1000, 8);

    // n=3
    runTest("Sample2", solver, string("0\n6\n28"), 1000, 3);

    // n=5
    runTest("Sample3", solver, string("0\n6\n28\n96\n252"), 1000, 5);

    // n=1
    runTest("Sample4", solver, string("0"), 1000, 1);

    return 0;
}
#endif
