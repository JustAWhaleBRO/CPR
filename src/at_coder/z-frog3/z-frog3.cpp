// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
using ll = long long;

ll solve(int N, ll C, const vector<ll> &h) {
    // TODO: Implement Frog 3 solution
    return 0;
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll C;
    cin >> N >> C;
    vector<ll> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    cout << solve(N, C, h) << endl;
    return 0;
}
#else
// ==================== END ATCODER SUBMISSION ====================

// Test harness mode - for local testing
#include "TestHarness.h"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solver = [](int N, ll C, const vector<ll> &h) {
        return solve(N, C, h);
    };

    // Sample 1
    runTest("Sample1", solver, 20LL, 2000,
        5, 6LL, vector<ll>{1, 2, 3, 4, 5}
    );

    // Sample 2
    runTest("Sample2", solver, 1250000000000LL, 2000,
        2, 1000000000000LL, vector<ll>{500000, 1000000}
    );

    // Sample 3
    runTest("Sample3", solver, 62LL, 2000,
        8, 5LL, vector<ll>{1, 3, 4, 5, 10, 11, 12, 13}
    );

    return 0;
}
#endif

