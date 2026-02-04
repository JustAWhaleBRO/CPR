// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll solve(int N, const vector<ll>& w, const vector<ll>& s, const vector<ll>& v) {
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

    vector<ll> w(N), s(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> s[i] >> v[i];
    }

    cout << solve(N, w, s, v) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const vector<ll>& w, const vector<ll>& s, const vector<ll>& v) -> ll {
        return solve(N, w, s, v);
    };

    // Sample 1: N=3
    // Expected: 3
    runTest("Sample1", solver, 3LL, 500,
        3,
        vector<ll>{2, 3, 8},
        vector<ll>{3, 10, 9},
        vector<ll>{4, 5, 6}
    );

    // Sample 2: N=4
    // Expected: 13
    runTest("Sample2", solver, 13LL, 500,
        4,
        vector<ll>{1, 4, 3, 5},
        vector<ll>{4, 3, 3, 10},
        vector<ll>{6, 4, 5, 2}
    );

    // Sample 3: N=5
    // Expected: 54
    runTest("Sample3", solver, 54LL, 500,
        5,
        vector<ll>{21, 13, 7, 18, 29},
        vector<ll>{81, 32, 96, 3, 76},
        vector<ll>{92, 37, 3, 78, 16}
    );

    // Sample 4: N=8
    // Expected: 287
    runTest("Sample4", solver, 287LL, 500,
        8,
        vector<ll>{36, 66, 39, 85, 42, 62, 11, 5},
        vector<ll>{96, 90, 6, 72, 51, 38, 90, 85},
        vector<ll>{73, 21, 13, 46, 96, 57, 68, 63}
    );

    return 0;
}
#endif
