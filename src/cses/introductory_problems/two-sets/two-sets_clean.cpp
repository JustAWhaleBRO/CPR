#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Set {
    vector<int> nums;
    ll sum;

    explicit Set() : sum(0) {}

    void insert(int num) {
        nums.emplace_back(num);
        sum += num;
    }

    void insert(const vector<int> &arr) {
        for (int num : arr) {
            insert(num);
        }
    }

    friend ostream& operator<<(ostream &os, const Set &s) {
        for (size_t i = 0; i < s.nums.size(); i++) {
            os << s.nums[i] << (i == s.nums.size() - 1 ? "" : " ");
        }
        return os;
    }
};

void solve(int n) {
    ll total_sum = (ll) n * (n + 1) / 2;
    if (total_sum % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    Set set1;
    Set set2;
    ll target_sum = total_sum / 2;

    for (int i = n; i >= 1; i--) {
        if (set1.sum + i <= target_sum) {
            set1.insert(i);
        } else {
            set2.insert(i);
        }
    }

    auto print_sol = [&]() {
        cout << set1.nums.size() << endl;
        cout << set1 << endl;
        cout << set2.nums.size() << endl;
        cout << set2 << endl;
    };

    print_sol();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    solve(n);
    return 0;
}
