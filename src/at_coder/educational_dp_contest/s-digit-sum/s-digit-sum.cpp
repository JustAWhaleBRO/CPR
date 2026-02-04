// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll solve(const string& K, int D) {
    // TODO: Implement the solution
    return 0;
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string K;
    int D;
    cin >> K >> D;

    cout << solve(K, D) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const string& K, const int& D) -> ll {
        return solve(K, D);
    };

    // Sample 1: K=30, D=4
    // Expected: 6
    runTest("Sample1", solver, 6LL, 500,
        string("30"), 4
    );

    // Sample 2: K=1000000009, D=1
    // Expected: 49
    runTest("Sample2", solver, 49LL, 500,
        string("1000000009"), 1
    );

    // Sample 3: K=1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890, D=1
    // Expected: 821346480
    runTest("Sample3", solver, 821346480LL, 500,
        string("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"), 1
    );

    return 0;
}
#endif
