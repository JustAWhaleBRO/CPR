// ==================== CSES SUBMISSION (copy from here) ====================
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include "Debug.h"
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

    auto solver = [](int n) -> string {
        ostringstream oss;
        streambuf* old = cout.rdbuf(oss.rdbuf());
        solve(n);
        cout.rdbuf(old);
        string result = oss.str();
        if (!result.empty() && result.back() == '\n') result.pop_back();
        return result;
    };

    // Sample 1: n=1 -> just 1
    runTest("Sample1", solver, string("1"), 1000, 1);

    // Sample 2: n=2 -> NO SOLUTION
    runTest("Sample2", solver, string("NO SOLUTION"), 1000, 2);

    // Sample 3: n=3 -> NO SOLUTION
    runTest("Sample3", solver, string("NO SOLUTION"), 1000, 3);

    // Sample 4: n=4 -> 2 4 1 3
    runTest("Sample4", solver, string("2 4 1 3"), 1000, 4);

    // Sample 5: n=5 -> 2 4 1 3 5
    runTest("Sample5", solver, string("2 4 1 3 5"), 1000, 5);

    // Sample 6: n=6 -> 2 4 6 1 3 5
    runTest("Sample6", solver, string("2 4 6 1 3 5"), 1000, 6);

    // Sample 7: n=7 -> 2 4 6 1 3 5 7
    runTest("Sample7", solver, string("2 4 6 1 3 5 7"), 1000, 7);

    return 0;
}
#endif
