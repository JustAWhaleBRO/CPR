// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <format>

using namespace std;

double solve(int N, const vector<int>& a, const vector<int> &count) {
    double p[N + 2][N + 2][N + 2]; // probability of state a, b, c (1 sushi, 2 sushi, 3 sushi)

    p[count[1]][count[2]][count[3]] = 1.0;
    double expected_value = 0.0;

    for (int c = count[3]; c >= 0; c--) {
        for (int b = count[3] + count[2]; b >= 0; b--) {
            for (int a = N; a >= 0; a--) {

                if (p[a][b][c] == 0.0) continue;
                if (a == 0 && b == 0 && c == 0) continue;

                double S = a + b + c;
                if (S > N) continue;

                expected_value += p[a][b][c] * N / S;

                if (c > 0) {
                    p[a][b + 1][c - 1] += c / S * p[a][b][c];
                }
                if (b > 0) {
                    p[a + 1][b - 1][c] += b / S * p[a][b][c];
                }
                if (a > 0) {
                    p[a - 1][b][c] += a / S * p[a][b][c];
                }
            }
        }
    }

    return expected_value;
}

#ifndef USE_TEST_HARNESS
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> cnt(4);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    cout << format("{:.10f}", solve(N, a, cnt)) << endl;
    return 0;
}
#endif
// ==================== END ATCODER SUBMISSION ====================


#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {

    auto solver = [](const int& N, const vector<int>& a, const vector<int> &count) -> double {
        return solve(N, a, count);
    };

    // Sample 1: N=3, a=[1, 1, 1]
    // Expected: 5.5
    runTest("Sample1", solver, 5.5, 500,
        3,
        vector<int>{1, 1, 1},
        vector<int>{0, 3, 0, 0}
    );

    // Sample 2: N=1, a=[3]
    // Expected: 3.0
    runTest("Sample2", solver, 3.0, 500,
        1,
        vector<int>{3},
        vector<int>{0, 0, 0, 1}
    );

    // Sample 3: N=2, a=[1, 2]
    // Expected: 4.5
    runTest("Sample3", solver, 4.5, 500,
        2,
        vector<int>{1, 2},
        vector<int>{0, 1, 1, 0}
    );

    runTest("Sample4", solver, 54.48064457488221, 500,
        10,
        vector<int>{1, 3, 2, 3, 3, 2, 3, 2, 1, 3},
        vector<int>{0, 2, 3, 5}
    );

    return 0;
}
#endif
