// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> solve(int N, ll M, const vector<int>& x, const vector<int>& y) {
    // TODO: Implement the solution
    return vector<ll>(N, 0);
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;

    vector<int> x(N-1), y(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> x[i] >> y[i];
    }

    vector<ll> result = solve(N, M, x, y);
    for (ll val : result) {
        cout << val << '\n';
    }
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const ll& M, const vector<int>& x, const vector<int>& y) -> vector<ll> {
        return solve(N, M, x, y);
    };

    // Sample 1: N=3, M=100, edges: (1,2), (2,3)
    // Expected: [101, 10200, 101]
    runTest("Sample1", solver, vector<ll>{101, 10200, 101}, 500,
        3, 100LL,
        vector<int>{1, 2},
        vector<int>{2, 3}
    );

    // Sample 2: N=4, M=1000000007, edges: (1,2), (1,3), (1,4)
    // Expected: [1, 1, 1, 1]
    runTest("Sample2", solver, vector<ll>{1, 1, 1, 1}, 500,
        4, 1000000007LL,
        vector<int>{1, 1, 1},
        vector<int>{2, 3, 4}
    );

    // Sample 3: N=6, M=2, edges: (1,2), (2,3), (3,4), (4,5), (5,6)
    // Expected: [3, 8, 20, 52, 135, 351]
    runTest("Sample3", solver, vector<ll>{3, 8, 20, 52, 135, 351}, 500,
        6, 2LL,
        vector<int>{1, 2, 3, 4, 5},
        vector<int>{2, 3, 4, 5, 6}
    );

    return 0;
}
#endif
