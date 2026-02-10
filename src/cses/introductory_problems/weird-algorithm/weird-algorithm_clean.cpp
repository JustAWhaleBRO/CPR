#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using ll = long long;

string solve(ll n) {
    ostringstream oss;
    oss << n;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        oss << " " << n;
    }
    return oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}
