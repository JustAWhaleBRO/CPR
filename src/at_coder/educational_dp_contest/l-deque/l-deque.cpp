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

int main() {

    auto solver = [](const int& N, const vector<ll>& a) -> ll {
        return solve(N, a);
    };

    // Sample 1: N=4, a=[10, 80, 90, 30]
    // Expected: 10
    runTest("Sample1", solver, 10LL, 500,
        4,
        vector<ll>{10, 80, 90, 30}
    );

    // Sample 2: N=3, a=[10, 100, 10]
    // Expected: -80
    runTest("Sample2", solver, -80LL, 500,
        3,
        vector<ll>{10, 100, 10}
    );

    // Sample 3: N=1, a=[10]
    // Expected: 10
    runTest("Sample3", solver, 10LL, 500,
        1,
        vector<ll>{10}
    );

    // Sample 4: N=10, a=[1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1]
    // Expected: 4999999995
    runTest("Sample4", solver, 4999999995LL, 500,
        10,
        vector<ll>{1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1}
    );

    return 0;
}
#endif
