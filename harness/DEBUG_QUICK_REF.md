# Debug.h - Quick Reference

Include: `#include "Debug.h"`

## Commands

| Command | Description |
|---------|-------------|
| `dbg(T... vars)` | Print any variable(s) |
| `dbg_arr(T* arr, size_t size)` | Print C-style array |
| `dbg_mat(vector<vector<T>>)` | Print 2D vector |
| `dbg_mat2d(T arr[R][C])` | Print 2D C-array |
| `dbg_dp(vector<T>)` | Print 1D DP array |
| `dbg_dp2d(vector<vector<T>>)` | Print 2D DP table |
| `dbg_dp2d_labeled(vector<vector<T>>, string, string)` | 2D DP with custom labels |
| `dbg_grid(vector<string>)` | Print char grid |
| `dbg_graph(vector<vector<T>>)` | Print adjacency list |
| `dbg_range(vector<T>, size_t, size_t)` | Print subarray [l..r] |
| `dbg_bin(T val, int numBits)` | Print binary representation |
| `dbg_section(string)` | Section separator |
| `dbg_iter(int index, T... vars)` | Debug in loop with iteration |
| `dbg_if(bool condition, T... vars)` | Conditional debug |
| `dbg_tree(vector<int>)` | Tree from parent array |
| `dbg_list(ListNode*)` | Linked list |
| `dbg_btree(TreeNode*)` | Binary tree (pretty) |
| `dbg_btree_bfs(TreeNode*)` | Binary tree (level-order) |

## Supported Data Structures

All these work automatically with `dbg(x)`:

| Type | Output Example |
|------|----------------|
| `int`, `double`, etc. | `42`, `3.14` |
| `string` | `"hello"` |
| `char` | `'A'` |
| `bool` | `true`, `false` |
| `pair<T,U>` | `(3, 5)` |
| `vector<T>` | `[1, 2, 3]` |
| `set<T>` | `{1, 2, 5}` |
| `multiset<T>` | `multiset{1, 1, 2}` |
| `unordered_set<T>` | `uset{1, 2, 5}` |
| `map<K,V>` | `{"a": 1, "b": 2}` |
| `unordered_map<K,V>` | `umap{"a": 1}` |
| `deque<T>` | `deque[1, 2, 3]` |
| `queue<T>` | `queue[front→1, 2←back]` |
| `stack<T>` | `stack[top→3, 2, 1←bottom]` |
| `priority_queue<T>` | `pq[top→8, 5, 2]` |
| `ListNode*` | `[1 → 2 → 3 → 4]` |
| `TreeNode*` | Tree structure (visual) |

## Linked List & Binary Tree

Requires standard LeetCode-style struct definitions:

```cpp
// Linked List (auto-detected)
struct ListNode {
    int val;
    ListNode* next;
    // ...constructors
};
dbg_list(head);  // [10] head = [1 → 2 → 3 → 4 → 5]

// Binary Tree (auto-detected)
struct TreeNode {
    int val;
    TreeNode *left, *right;
    // ...constructors
};
dbg_btree(root);      // Pretty tree visualization
dbg_btree_bfs(root);  // Level-order: [1, 2, 3, null, 4]
```

## Examples

```cpp
#include "Debug.h"

int x = 42;
dbg(x);                    // [10] x = 42

vector<int> v = {1,2,3};
dbg(v);                    // [12] v = [1, 2, 3]

int arr[] = {1,2,3,4,5};
dbg_arr(arr, 5);           // [15] arr = [1, 2, 3, 4, 5]

vector<vector<int>> dp = {{1,2},{3,4}};
dbg_mat(dp);               // Pretty matrix with indices
dbg_dp2d(dp);              // 2D DP table with row/col labels

// Knapsack DP with weight label
dbg_dp2d_labeled(dp, "item", "weight");

map<int,string> m = {{1,"a"},{2,"b"}};
dbg(m);                    // [20] m = {1: "a", 2: "b"}

dbg_bin(13, 8);            // [22] 13 = 0b0000'1101

// Containers
queue<int> q; q.push(1); q.push(2);
dbg(q);                    // queue[front→1, 2←back]

set<int> s = {5, 2, 8};
dbg(s);                    // {2, 5, 8}

deque<int> dq = {1, 2, 3};
dbg(dq);                   // deque[1, 2, 3]
```

## Disable for Submission

Compile with `-DNO_DEBUG` to disable all debug output.


