#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll solve(int n, const vector<int>& nums) {
    ll remainder = (ll) n * (n + 1) / 2;
    for (int num : nums) {
        remainder -= num;
    }
    return remainder;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> nums[i];
    }
    cout << solve(n, nums) << "\n";
    return 0;
}
