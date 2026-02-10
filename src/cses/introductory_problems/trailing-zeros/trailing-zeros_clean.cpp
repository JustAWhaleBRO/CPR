#include <iostream>
using namespace std;
using ll = long long;

ll solve(int n) {
    ll count = 0;
    while (n > 0) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
