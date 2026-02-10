#include <iostream>
#include <string>
#include <format>
#include <vector>
using namespace std;

vector<string> res;

void dfs(int curr, int level, int last_level, bool invert_order) {
    if (level == last_level) {
        res.emplace_back(format("{:0{}b}", curr, last_level));
        return;
    }
    if (!invert_order) {
        dfs(curr, level + 1, last_level, false);
        dfs(curr | (1 << level), level + 1, last_level, true);
    } else {
        dfs(curr | (1 << level), level + 1, last_level, false);
        dfs(curr, level + 1, last_level, true);
    }
}

void solve(int n) {
    dfs(0, 0, n, false);
    for (string code : res) {
        cout << code << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    solve(n);
    return 0;
}
