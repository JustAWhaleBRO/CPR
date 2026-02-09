// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void solve(string s) {
    // TODO: Implement solution
}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    solve(s);
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"
#include <sstream>

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    auto solver = [](const string& s) -> string {
        ostringstream oss;
        streambuf* old = cout.rdbuf(oss.rdbuf());
        solve(s);
        cout.rdbuf(old);
        string result = oss.str();
        if (!result.empty() && result.back() == '\n') result.pop_back();
        return result;
    };

    // Sample 1: aabac
    runTest("Sample1", solver, string("20\naaabc\naabac\naabca\naacab\naacba\nabaca\nabcaa\nacaab\nacaba\nacbaa\nbaaac\nbaaca\nbacaa\nbcaaa\ncaaab\ncaaba\ncabaa\ncbaaa"), 1000, string("aabac"));

    // Single char
    runTest("Sample2", solver, string("1\na"), 1000, string("a"));

    return 0;
}
#endif
