#include <iostream>
using namespace std;
using ll = long long;

ll solve(ll row, ll col) {
    int layer = max(row, col);
    if (layer % 2 == 0) {
        swap(row, col);
    }
    if (row == layer) {
        return (row - 1) * (row - 1) + 1 + (col - 1);

    } else {
        return col * col - (row - 1);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        cout << solve(y, x) << "\n";
    }
    return 0;
}
