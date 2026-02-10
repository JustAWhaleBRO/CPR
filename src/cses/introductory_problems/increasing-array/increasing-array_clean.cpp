#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll solve(int n, vector<int> arr) {
    ll move_counts = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            move_counts += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    return move_counts;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(n, arr) << "\n";
    return 0;
}
