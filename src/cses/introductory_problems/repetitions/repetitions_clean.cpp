#include <iostream>
#include <string>
using namespace std;

int solve(const string& s) {
    int longest = 1;
    int curr_len = 1;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == s[i - 1]) {
            curr_len++;
            longest = max(longest, curr_len);
        } else {
            curr_len = 1;
        }
    }
    return longest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << solve(s) << "\n";
    return 0;
}
