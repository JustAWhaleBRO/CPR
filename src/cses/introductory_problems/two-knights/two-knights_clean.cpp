#include <vector>
#include <iostream>
using namespace std;
using ll = long long;

int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dr[] = {2, 1, -1, -2, -2, -1, 1, 2};

ll solve(int n) {
    int board_size = n * n;
    ll all_ways = (ll) board_size * (board_size - 1) / 2;

    ll bad_ways = (n - 4) * (n - 4) * 8;
    bad_ways += (n - 4) * 4 * 6;
    bad_ways += (n - 3) * 4 * 4;
    bad_ways += 8 * 3 + 4 * 2;
    bad_ways /= 2;

    return all_ways - bad_ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        cout << solve(k) << "\n";
    }
    return 0;
}
