// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll solve(int N, int M, const vector<int>& l, const vector<int>& r, const vector<ll>& a) {
    // TODO: Implement the solution
    return 0;
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> l(M), r(M);
    vector<ll> a(M);
    for (int i = 0; i < M; i++) {
        cin >> l[i] >> r[i] >> a[i];
    }

    cout << solve(N, M, l, r, a) << '\n';
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const int& M, const vector<int>& l, const vector<int>& r, const vector<ll>& a) -> ll {
        return solve(N, M, l, r, a);
    };

    // Sample 1: N=5, M=3
    // Expected: 10
    runTest("Sample1", solver, 10LL, 500,
        5, 3,
        vector<int>{1, 3, 1},
        vector<int>{3, 5, 5},
        vector<ll>{10, 10, 1}
    );

    // Sample 2: N=10, M=4
    // Expected: 2
    runTest("Sample2", solver, 2LL, 500,
        10, 4,
        vector<int>{1, 2, 3, 4},
        vector<int>{2, 3, 4, 5},
        vector<ll>{1, 2, 3, 4}
    );

    // Sample 3: N=1000000000, M=10
    // Expected: 157
    runTest("Sample3", solver, 157LL, 500,
        1000000000, 10,
        vector<int>{535923366, 899271365, 162196748, 83061485, 925922592, 331180708, 288372505, 590035485, 962686939, 462772910},
        vector<int>{793655426, 946647739, 443545894, 962706319, 994513050, 607995777, 382061296, 887429514, 996355324, 499878871},
        vector<ll>{50, 51, 77, 90, 29, 68, 29, 94, 26, 58}
    );

    return 0;
}
#endif
