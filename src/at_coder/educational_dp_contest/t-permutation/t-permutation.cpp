// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll solve(int N, const string& s) {
    // TODO: Implement the solution
    return 0;
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;

    cout << solve(N, s) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const int& N, const string& s) -> ll {
        return solve(N, s);
    };

    // Sample 1: N=4, s="<><"
    // Expected: 5
    runTest("Sample1", solver, 5LL, 500,
        4, string("<><")
    );

    // Sample 2: N=5, s=">>>>"
    // Expected: 1
    runTest("Sample2", solver, 1LL, 500,
        5, string(">>>>")
    );

    // Sample 3: N=20, s="<>>>><>><>><<<<>>>>"
    // Expected: 217136290
    runTest("Sample3", solver, 217136290LL, 500,
        20, string("<>>>><>><>><<<<>>>>")
    );

    return 0;
}
#endif
