// ==================== ATCODER SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using ll = long long;

struct Line {
    ll a;
    ll b;
    ll eval(ll x) const {
        return a * x + b;
    }
    explicit Line(ll a, ll b) : a(a), b(b) {}
};

class ConvexHullTrick {
    deque<Line> dq;

    bool is_bad(const Line &l1, const Line &l2, const Line &l3) {
        return (__int128)(l3.b - l1.b) * (l1.a - l2.a) <= (__int128)(l2.b - l1.b) * (l1.a - l3.a);
    }

public:
    void add_line(ll a, ll b) {
        Line new_line(a ,b);
        while (dq.size() >= 2 && is_bad(dq[dq.size() - 2], dq.back(), new_line)) {
            dq.pop_back();
        }
        dq.push_back(new_line);
    }

    ll query(ll x) {
        while (dq.size() >= 2 && dq[1].eval(x) < dq.front().eval(x)) {
            dq.pop_front();
        }
        return dq.front().eval(x);
    }
};

ll solve(int N, ll C, const vector<ll> &h) {
    vector<ll> dp(N);
    ConvexHullTrick cht;

    dp[0] = 0;
    cht.add_line(-2 * h[0], h[0] * h[0]);
    for (int i = 1; i < N; i++) {
        ll best_prev_cost = cht.query(h[i]);

        dp[i] = best_prev_cost + h[i] * h[i] + C;

        cht.add_line(-2 * h[i], dp[i] + h[i] * h[i]);
    }
    return dp[N - 1];
}

#ifndef USE_TEST_HARNESS
#define NO_DEBUG
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
#endif
// ==================== END ATCODER SUBMISSION ====================

// Test harness mode - for local testing
#include "TestHarness.h"

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);
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

