#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
using namespace std;

void solve(int n) {
    if (n == 1) {
        cout << "1" << endl;
        return;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    deque<int> permutation;

    int l = 1;
    int r = n;
    while (l < r) {
        permutation.emplace_back(l++);
        permutation.emplace_back(r--);
    }

    if (r == l) {
        permutation.emplace_back(r);
    }

    int last = permutation.back();
    permutation.pop_back();
    permutation.emplace_front(last);

    for (int i = 0; i < n; i++) {
        cout << permutation[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    solve(n);
    return 0;
}
