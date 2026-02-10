#include <iostream>
using namespace std;
using ll = long long;

string solve(ll a, ll b) {
    if (max(a, b) > 2 * min(a, b)) {
        return "NO";
    }
    ll sum = 10 * a + b;
    if (sum % 3 ==0) {
        return "YES";
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}
