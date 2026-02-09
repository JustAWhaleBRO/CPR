// ==================== ATCODER SUBMISSION (copy from here) ====================
#include "Debug.h"
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template <typename T>
class FenwickTree {
    vector<T> tree_;

    int Lsb(int i) const {
        return i & -i;
    }

public:
    explicit FenwickTree(int size) : tree_(size + 1) {}

    explicit FenwickTree(const vector<T> &arr) : tree_(arr.size() + 1) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            tree_[i + 1] = arr[i];
        }

        for (int i = 1; i <= n; i++) {
            int parent = i + Lsb(i);

            if (parent <= n) {
                tree_[parent] += tree_[i];
            }
        }
    }

    T prefix_sum(int i) const {
        T res = 0;
        while (i > 0) {
            res += tree_[i];
            i -= Lsb(i);
        }
        return res;
    }

    void add(int i, T val) {
        while (i < tree_.size()) {
            tree_[i] += val;
            i += Lsb(i);
        }
    }

    T range_sum(int l, int r) const {
        if (l > r) return 0;
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

template <typename T>
class MaxFenwickTree {
    vector<T> tree_;

    int Lsb(int i) const {
        return i & -i;
    }

public:
    explicit MaxFenwickTree(int size) : tree_(size + 1) {
        dbg_section("MaxFenwickTree Init");
        dbg(size, tree_.size());
    }

    explicit MaxFenwickTree(const vector<T> &arr) : tree_(arr.size() + 1) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            tree_[i + 1] = arr[i];
        }

        for (int i = 1; i <= n; i++) {
            int parent = i + Lsb(i);

            if (parent <= n) {
                tree_[parent] = max(tree_[parent], tree_[i]);
            }
        }
    }

    T prefix_max(int i) const {
        dbg_section("prefix_max query");
        dbg(i);
        T res = 0;
        int orig_i = i;
        while (i > 0) {
            dbg(i, tree_[i], res);
            res = max(res, tree_[i]);
            i -= Lsb(i);
        }
        dbg(orig_i, res);
        return res;
    }

    void update_max(int i, T val) {
        dbg_section("update_max");
        dbg(i, val);
        while (i < (int)tree_.size()) {
            T old_val = tree_[i];
            tree_[i] = max(tree_[i], val);
            dbg(i, old_val, tree_[i]);
            i += Lsb(i);
        }
        dbg(tree_);
    }
};

ll solve(int N, const vector<int>& h, const vector<int>& a) {
    dbg_section("SOLVE START");
    dbg(N, h, a);

    MaxFenwickTree<ll> bit(N); // max beauty for a sequence of increasing flowers ending at flower with height i
    ll global_max = 0;

    for (int flower = 0; flower < N; flower++) {
        int curr_height = h[flower];
        ll curr_beauty = a[flower];  // promote to ll for calculations

        dbg_section("Processing flower");
        dbg(flower, curr_height, curr_beauty);

        ll max_prev_beauty = bit.prefix_max(curr_height - 1);
        ll cur_max_beauty = max_prev_beauty + curr_beauty;

        dbg(max_prev_beauty, cur_max_beauty);

        bit.update_max(curr_height, cur_max_beauty);

        global_max = max(global_max, cur_max_beauty);
        dbg(global_max);
    }

    dbg_section("FINAL RESULT");
    dbg(global_max);
    return global_max;
}

#ifndef USE_TEST_HARNESS
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> a(N);
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

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const int& N, const vector<int>& h, const vector<int>& a) -> ll {
        return solve(N, h, a);
    };

    // Sample 1: N=4, h=[3, 1, 4, 2], a=[10, 20, 30, 40]
    // Expected: 60
    runTest("Sample1", solver, 60LL, 500,
        4,
        vector<int>{3, 1, 4, 2},
        vector<int>{10, 20, 30, 40}
    );

    // Sample 2: N=1, h=[1], a=[10]
    // Expected: 10
    runTest("Sample2", solver, 10LL, 500,
        1,
        vector<int>{1},
        vector<int>{10}
    );

    // Sample 3: N=5, h=[1, 2, 3, 4, 5], a=[1000000000, 1000000000, 1000000000, 1000000000, 1000000000]
    // Expected: 5000000000
    runTest("Sample3", solver, 5000000000LL, 500,
        5,
        vector<int>{1, 2, 3, 4, 5},
        vector<int>{1000000000, 1000000000, 1000000000, 1000000000, 1000000000}
    );

    // Sample 4: N=9
    // Expected: 31
    runTest("Sample4", solver, 31LL, 500,
        9,
        vector<int>{4, 2, 5, 8, 3, 6, 1, 7, 9},
        vector<int>{6, 8, 8, 4, 6, 3, 5, 7, 5}
    );

    return 0;
}
#endif
