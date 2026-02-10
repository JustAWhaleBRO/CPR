#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll solve(int n) {
    ll res = 1;
    for (int i = 0; i < n; i++) {
        res = (2 * res) % MOD;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
