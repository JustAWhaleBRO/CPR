// ==================== LEETCODE SUBMISSION (copy from here) ====================
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row, col, MAX_ROWS, MAX_COLS;
        MAX_ROWS = image.size();
        MAX_COLS = image[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        stack<pair<int, int>> s;
        int starting_color = image[sr][sc];
        s.emplace(sr, sc);

        while (!s.empty()) {
            auto [x, y] = s.top(); s.pop();
            image[x][y] = color;
            if (color == starting_color) { break; }
            for (int i = 0; i < 4; i++) {
                row = x + dx[i];
                col = y + dy[i];

                if (row < MAX_ROWS && row >= 0 && col < MAX_COLS && col >= 0 && image[row][col] == starting_color) {
                    s.emplace(row, col);
                }
            }
        }
        return image;
    }
};

#ifndef USE_TEST_HARNESS
int main() {
    return 0;
}
#endif
// ==================== END LEETCODE SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

int main() {
    Solution sol;

    runTest(
        "Test Case 1",
        [&]() {
            vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
            int sr = 1, sc = 1, color = 2;
            return sol.floodFill(image, sr, sc, color);
        },
        vector<vector<int>>{{2,2,2},{2,2,0},{2,0,1}},
        1000
    );

    runTest(
        "Test Case 2",
        [&]() {
            vector<vector<int>> image = {{0,0,0},{0,0,0}};
            int sr = 0, sc = 0, color = 0;
            return sol.floodFill(image, sr, sc, color);
        },
        vector<vector<int>>{{0,0,0},{0,0,0}},
        1000
    );

    return 0;
}
#endif
