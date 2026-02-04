// Test file for Debug.h - Run to see all debug features
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include "Debug.h"

using namespace std;

// LeetCode-style ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

// LeetCode-style TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main() {
    // ==================== Basic Variables ====================
    dbg_section("Basic Variables");

    int x = 42;
    double pi = 3.14159;
    string name = "AtCoder";
    bool flag = true;
    char ch = 'A';

    dbg(x);
    dbg(pi);
    dbg(name);
    dbg(flag, ch);
    dbg(x, pi, name);  // Multiple in one line

    // ==================== Pairs ====================
    dbg_section("Pairs");

    pair<int, int> p = {3, 5};
    pair<string, double> p2 = {"score", 95.5};
    dbg(p);
    dbg(p2);

    // ==================== Vectors ====================
    dbg_section("Vectors");

    vector<int> nums = {10, 20, 30, 40, 50};
    vector<string> words = {"hello", "world"};
    vector<pair<int,int>> edges = {{1,2}, {2,3}, {3,4}};

    dbg(nums);
    dbg(words);
    dbg(edges);

    // ==================== C-style Arrays ====================
    dbg_section("C-style Arrays");

    int arr[] = {1, 2, 3, 4, 5};
    double darr[] = {1.1, 2.2, 3.3};

    dbg_arr(arr, 5);
    dbg_arr(darr, 3);

    // ==================== 2D Matrix (vector) ====================
    dbg_section("2D Matrix (vector<vector>)");

    vector<vector<int>> dp = {
        {0, 1, 2, 3},
        {1, 2, 4, 6},
        {2, 4, 8, 12},
        {3, 6, 12, 18}
    };
    dbg_mat(dp);

    // ==================== 2D C-style Array ====================
    dbg_section("2D C-style Array");

    int grid[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    dbg_mat2d(grid);

    // ==================== Character Grid ====================
    dbg_section("Character Grid (for maze/board problems)");

    vector<string> maze = {
        "...#..",
        ".#....",
        "....#.",
        "#....."
    };
    dbg_grid(maze);

    // ==================== 1D DP Table ====================
    dbg_section("1D DP Table");

    vector<long long> dp1d = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    dbg_dp(dp1d);

    // ==================== 2D DP Table ====================
    dbg_section("2D DP Table (for knapsack)");

    // Example: Knapsack DP table (items x weight)
    vector<vector<int>> knapsack_dp = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 3, 3, 3, 3},
        {0, 0, 3, 4, 4, 7},
        {0, 0, 3, 4, 5, 7}
    };
    dbg_dp2d(knapsack_dp);

    // With custom labels (item, weight)
    dbg_dp2d_labeled(knapsack_dp, "item", "weight");

    // ==================== Graph (Adjacency List) ====================
    dbg_section("Graph (Adjacency List)");

    vector<vector<int>> adj(5);
    adj[0] = {1, 2};
    adj[1] = {2, 3};
    adj[2] = {3, 4};
    adj[3] = {4};
    adj[4] = {};

    dbg_graph(adj);

    // ==================== Sets ====================
    dbg_section("Sets");

    set<int> s = {5, 2, 8, 1, 9};
    multiset<int> ms = {1, 1, 2, 2, 3};

    dbg(s);
    dbg(ms);

    // ==================== Maps ====================
    dbg_section("Maps");

    map<string, int> scores = {{"Alice", 100}, {"Bob", 95}, {"Charlie", 88}};
    map<int, vector<int>> groups = {{1, {10, 20}}, {2, {30, 40, 50}}};

    dbg(scores);
    dbg(groups);

    // ==================== Unordered Set/Map ====================
    dbg_section("Unordered Set / Unordered Map");

    unordered_set<int> us = {5, 2, 8, 1, 9};
    unordered_map<string, int> um = {{"Alice", 100}, {"Bob", 95}};

    dbg(us);
    dbg(um);

    // ==================== Deque ====================
    dbg_section("Deque");

    deque<int> dq = {1, 2, 3, 4, 5};
    dbg(dq);

    // ==================== Queue / Stack / Priority Queue ====================
    dbg_section("Queue / Stack / Priority Queue");

    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    dbg(q);

    stack<int> st;
    st.push(10); st.push(20); st.push(30);
    dbg(st);

    priority_queue<int> pq;
    pq.push(5); pq.push(2); pq.push(8);
    dbg(pq);

    // ==================== Binary Representation ====================
    dbg_section("Binary Representation");

    int mask = 13;  // 1101 in binary
    dbg_bin(mask, 8);

    int bitmask = 0b10110011;
    dbg_bin(bitmask, 8);

    // ==================== Range Debug ====================
    dbg_section("Range Debug (subarray)");

    vector<int> data = {0, 10, 20, 30, 40, 50, 60, 70};
    dbg_range(data, 2, 5);  // Print data[2..5]

    // ==================== Iteration Debug ====================
    dbg_section("Iteration Debug (in loops)");

    for (int i = 0; i < 3; i++) {
        int val = i * i;
        dbg_iter(i, val, nums[i]);
    }

    // ==================== Conditional Debug ====================
    dbg_section("Conditional Debug");

    for (int i = 0; i < 5; i++) {
        dbg_if(i % 2 == 0, i, "is even");  // Only prints when condition is true
    }

    // ==================== Tree (parent array) ====================
    dbg_section("Tree (parent array)");

    vector<int> parent = {-1, 0, 0, 1, 1, 2};  // -1 means root
    dbg_tree(parent);

    // ==================== Linked List ====================
    dbg_section("Linked List (LeetCode-style)");

    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    dbg_list(head);

    ListNode* empty_list = nullptr;
    dbg_list(empty_list);

    // ==================== Binary Tree ====================
    dbg_section("Binary Tree (LeetCode-style)");

    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, nullptr, new TreeNode(6))
    );
    dbg_btree(root);
    dbg_btree_bfs(root);

    TreeNode* empty_tree = nullptr;
    dbg_btree(empty_tree);

    // ==================== Large Values (alignment test) ====================
    dbg_section("Large Values (alignment test)");

    vector<vector<long long>> big_dp = {
        {0, 100000, 200000, 300000},
        {100000, 150000, 250000, 350000},
        {200000, 250000, 400000, 500000}
    };
    dbg_dp2d(big_dp);
    dbg_dp2d_labeled(big_dp, "item", "capacity");

    // ==================== Test long label alignment ====================
    dbg_section("Long Label Alignment Test");

    vector<vector<int>> test_dp = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 3, 3, 3, 3},
        {0, 0, 3, 4, 4, 7},
        {0, 0, 3, 4, 5, 7}
    };
    dbg_dp2d_labeled(test_dp, "item", "weight");
    dbg_dp2d_labeled(test_dp, "row_index", "column_index");

    cout << "\n✓ All debug features demonstrated!\n";
    return 0;
}
