#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solve(const string& s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }
    int n = freq.size();

    char odd_char = -1;
    for (int i = 0; i < n; i++) {
        if (freq[i] % 2 == 1) {
            if (odd_char != -1) return "NO SOLUTION";
            odd_char = i + 'A';
        }
    }

    string res = "";
    for (int i = 0; i < n; i++) {
        char c = i + 'A';

        if (c == odd_char) {
            continue;
        }

        for (int k = 0; k < freq[i] / 2; k++) {
            res.push_back(c);
        }
    }

    // Build the second half
    string right_half = res;
    reverse(right_half.begin(), right_half.end());

    if (odd_char != -1) {
        int odd_char_idx = odd_char - 'A';
        for (int i = 0; i < freq[odd_char_idx]; i++) {
            res.push_back(odd_char);
        }
    }

    // Append the second half
    res += right_half;

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << solve(s) << "\n";
    return 0;
}
