// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll solve(int N, const vector<int>& h, const vector<ll>& a) {
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

    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve(N, h, a) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const vector<int>& h, const vector<ll>& a) -> ll {
        return solve(N, h, a);
    };

    // Sample 1: N=4, h=[3, 1, 4, 2], a=[10, 20, 30, 40]
    // Expected: 60
    runTest("Sample1", solver, 60LL, 500,
        4,
        vector<int>{3, 1, 4, 2},
        vector<ll>{10, 20, 30, 40}
    );

    // Sample 2: N=1, h=[1], a=[10]
    // Expected: 10
    runTest("Sample2", solver, 10LL, 500,
        1,
        vector<int>{1},
        vector<ll>{10}
    );

    // Sample 3: N=5, h=[1, 2, 3, 4, 5], a=[1000000000, 1000000000, 1000000000, 1000000000, 1000000000]
    // Expected: 5000000000
    runTest("Sample3", solver, 5000000000LL, 500,
        5,
        vector<int>{1, 2, 3, 4, 5},
        vector<ll>{1000000000, 1000000000, 1000000000, 1000000000, 1000000000}
    );

    // Sample 4: N=9
    // Expected: 370
    runTest("Sample4", solver, 370LL, 500,
        9,
        vector<int>{4, 2, 5, 8, 3, 6, 1, 7, 9},
        vector<ll>{6, 8, 8, 4, 6, 3, 5, 7, 5}
    );

    return 0;
}
#endif
