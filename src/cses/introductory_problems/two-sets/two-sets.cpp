// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve(int n) {

}

#ifndef USE_TEST_HARNESS
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    solve(n);
    return 0;
}
#endif
// ==================== END CSES SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"
#include <sstream>

int main(int argc, char* argv[]) {
    PARSE_TEST_ARGS(argc, argv);

    // Validator: check if output is valid (not exact match due to multiple solutions)
    auto validator = [](int n) -> string {
        ostringstream oss;
        streambuf* old = cout.rdbuf(oss.rdbuf());
        solve(n);
        cout.rdbuf(old);
        string result = oss.str();
        if (!result.empty() && result.back() == '\n') result.pop_back();
        return result;
    };

    // Sample 1: n=7 -> YES with valid partition
    // Expected format: YES\n3\n... (but multiple valid solutions exist)
    runTest("Sample1", validator, string("YES\n3\n7 6 1\n4\n5 4 3 2"), 1000, 7);

    // Sample 2: n=6 -> NO (sum = 21, odd)
    runTest("Sample2", validator, string("NO"), 1000, 6);

    return 0;
}
#endif

