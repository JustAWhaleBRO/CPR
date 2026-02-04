// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll solve(int N, const vector<ll>& a) {
    // TODO: Implement the solution
    return 0;
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve(N, a) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const int& N, const vector<ll>& a) -> ll {
        return solve(N, a);
    };

    // Sample 1: N=4, a=[10, 20, 30, 40]
    // Expected: 190
    runTest("Sample1", solver, 190LL, 500,
        4,
        vector<ll>{10, 20, 30, 40}
    );

    // Sample 2: N=5, a=[10, 10, 10, 10, 10]
    // Expected: 120
    runTest("Sample2", solver, 120LL, 500,
        5,
        vector<ll>{10, 10, 10, 10, 10}
    );

    // Sample 3: N=3, a=[1000000000, 1000000000, 1000000000]
    // Expected: 5000000000
    runTest("Sample3", solver, 5000000000LL, 500,
        3,
        vector<ll>{1000000000, 1000000000, 1000000000}
    );

    // Sample 4: N=6, a=[7, 6, 8, 6, 1, 1]
    // Expected: 68
    runTest("Sample4", solver, 68LL, 500,
        6,
        vector<ll>{7, 6, 8, 6, 1, 1}
    );

    return 0;
}
#endif
