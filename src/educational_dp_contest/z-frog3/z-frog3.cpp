#include "TestHarness.h"

using namespace std;
using ll = long long;

ll solve_z_frog3(int N, ll C, const vector<ll> &h) {
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Wrap solver for the test harness: function taking (N, C, h)
    auto solver = [](int N, long long C, const vector<long long> &h) {
        return solve_z_frog3(N, C, h);
    };

    runTest("Sample1", solver, 20, 2000,
        5, 6, vector<long long>{1,2,3,4,5}
        );

    // Sample 2
    runTest("Sample2", solver, 1250000000000, 200,
        2, 1000000000000, vector<long long>{500000,1000000}
        );

    // Sample 3
    runTest("Sample3", solver, 62, 200,
        8, 5, vector<long long>{1,3,4,5,10,11,12,13});

    return 0;
}

