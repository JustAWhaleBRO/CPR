# Debug.h - Quick Reference

**What:** 30+ pre-built debug macros for competitive programming  
**Where:** Include in your solution: `#include "Debug.h"`  
**When:** Use while developing locally; automatically removed on submission  
**Result:** Beautiful formatted output for algorithms, data structures, and DP tables

---

## Why Debug Macros?

When solving competitive programming problems, you often need to:
- **Visualize data structures** (see what's in your DP table, graph, tree)
- **Trace execution** (understand what values change through iterations)
- **Debug quickly** (see output without manual formatting)
- **Switch between debug and clean output** (test locally vs submit cleanly)

CPR's debug macros solve all of this:
- `dbg()` – Print any variable instantly
- `dbg_dp2d()` – See DP tables formatted as grids
- `dbg_graph()` – Visualize graph connections
- `dbg_btree()` – See binary tree structure visually
- **And 25+ more** for every common data structure

**Key feature:** All debug code stays in your file. On submission, the `extract` command removes it automatically.

---

For commands and workflow → [CMD_REFERENCE.md](../CMD_REFERENCE.md)

---

## Quick Start: Print Variables Instantly

```cpp
int x = 42;
dbg(x);                    // Output: [line] x = 42

vector<int> v = {1, 2, 3};
dbg(v);                    // Output: [line] v = [1, 2, 3]

map<string, int> m = {{"a", 1}, {"b", 2}};
dbg(m);                    // Output: [line] m = {"a": 1, "b": 2}

// Works with ANY data type automatically!
```

---

## Debug Macros

**All macros work the same way:** Set `DEBUG_ENABLED=1` when running to see output; remove it to run cleanly  
**Pro tip:** Use `make run-debug` instead of setting the environment variable manually

### Basic Output

| Macro | What It Does | Example |
|-------|--------------|---------|
| `dbg(vars...)` | Print any variables | `dbg(x, y, z)` → `[10] x = 5, y = 10, z = 15` |
| `dbg_section("title")` | Mark sections in output | `dbg_section("After sort")` → Shows separator |
| `dbg_iter(i, vars...)` | Debug in loops with iteration number | `dbg_iter(i, arr[i])` → `[25] iter 0: [1, 2, 3]` |
| `dbg_if(cond, vars...)` | Debug only if condition true | `dbg_if(x < 10, x)` → Only prints if x < 10 |

### Arrays & Matrices

| Macro | What It Does | Best For |
|-------|--------------|----------|
| `dbg_arr(arr, size)` | C-style arrays | `int arr[5] = {1,2,3,4,5}` |
| `dbg_mat(vec2d)` | 2D vectors | `vector<vector<int>>` |
| `dbg_mat2d(arr2d)` | 2D C-arrays | `int arr[5][5]` |
| `dbg_grid(vec<string>)` | Character grids (mazes, boards) | `vector<string> grid = {"#.#", "..."}` |

### Dynamic Programming (DP)

| Macro | What It Does | Best For |
|-------|--------------|----------|
| `dbg_dp(vec)` | 1D DP array with indices | Coin change, unbounded knapsack |
| `dbg_dp2d(vec2d)` | 2D DP table with grid layout | Knapsack, LCS, matrix DP |
| `dbg_dp2d_labeled(dp, "row", "col")` | 2D DP with custom axis labels | `dbg_dp2d_labeled(dp, "item", "capacity")` |

### Graphs, Trees & Data Structures

| Macro | What It Does | Best For |
|-------|--------------|----------|
| `dbg_graph(adj)` | Directed graph visualization | Adjacency list representation |
| `dbg_ugraph(adj)` | Undirected graph | Bidirectional connections |
| `dbg_tree(parent)` | Tree from parent array | Given parent pointers, visualize tree |
| `dbg_list(ListNode*)` | Linked list | `1 → 2 → 3 → 4 → null` |
| `dbg_btree(TreeNode*)` | Binary tree (pretty print) | Visual tree structure |

### Binary & Bit Operations

| Macro | What It Does | Example |
|-------|--------------|---------|
| `dbg_bin(val, bits)` | Binary representation | `dbg_bin(13, 8)` → `13 = 0b0000'1101` |
| `dbg_bits(val)` | Binary (auto-size) | `dbg_bits(5)` → `5 = 0b101` |
| `dbg_range(vec, l, r)` | Subarray [l..r] | `dbg_range(arr, 2, 5)` → Shows arr[2..5] |

---

## Auto-Supported Data Types

**`dbg()` automatically works with these types** – just pass them in, no special macro needed:

| Type | Output Format | When You Use It |
|------|----------------|-----------------|
| `int`, `double`, `string`, `char`, `bool` | `42`, `3.14`, `"hello"`, `'A'`, `true` | Basic variables |
| `pair<T,U>` | `(3, 5)` | Pairs of values |
| `vector<T>` | `[1, 2, 3]` | Dynamic arrays |
| `set<T>`, `multiset<T>` | `{1, 2, 5}`, `multiset{1, 1, 2}` | Unique/duplicate elements sorted |
| `map<K,V>`, `unordered_map<K,V>` | `{"a": 1, "b": 2}` | Key-value pairs |
| `deque<T>` | `deque[1, 2, 3]` | Double-ended queue |
| `queue<T>` | `queue[front→1, 2←back]` | FIFO structure |
| `stack<T>` | `stack[top→3, 2, 1←bottom]` | LIFO structure |
| `priority_queue<T>` | `pq[top→8, 5, 2]` | Max-heap |
| `ListNode*`, `TreeNode*` | Visual structures | LeetCode linked lists & trees |

**Example:**
```cpp
dbg(v);           // If v is vector, automatically prints [1, 2, 3]
dbg(m);           // If m is map, automatically prints {"key": value}
dbg(s);           // If s is stack, automatically prints stack[top→x, y←bottom]
```

---

## Real-World Examples

**1. Debugging a simple loop:**
```cpp
vector<int> arr = {5, 2, 8, 1};
for (int i = 0; i < arr.size(); i++) {
    dbg_iter(i, arr[i]);  // Shows: [25] iter 0: 5, [25] iter 1: 2, etc.
}
```

**2. Visualizing a DP table (e.g., coin change):**
```cpp
vector<vector<int>> dp(n, vector<int>(m, 0));
dbg_section("After initialization");
dbg_dp2d(dp);  // Shows formatted table with row/col indices
```

**3. Labeled DP table (knapsack problem):**
```cpp
vector<vector<int>> dp(items, vector<int>(capacity + 1));
dbg_section("Knapsack DP Table");
dbg_dp2d_labeled(dp, "item", "weight");  // Shows "item" on rows, "weight" on cols
```

**4. Debugging a map (e.g., frequency counter):**
```cpp
map<int, int> freq;
for (int x : arr) freq[x]++;
dbg("Frequency map:", freq);  // Shows: [30] Frequency map: {1: 2, 5: 1, 8: 1}
```

**5. Visualizing a graph (adjacency list):**
```cpp
vector<vector<int>> adj(n);
// ... build graph ...
dbg_graph(adj);  // Shows all connections visually
```

**6. Debugging a linked list (LeetCode):**
```cpp
ListNode* head = new ListNode(1);
head->next = new ListNode(2);
// ...
dbg_list(head);  // Shows: [1 → 2 → 3 → 4 → null]
```

**7. Visualizing a binary tree (LeetCode):**
```cpp
TreeNode* root = new TreeNode(1);
// ...
dbg_btree(root);  // Shows pretty tree structure
```

**8. Binary representation (bit manipulation):**
```cpp
int mask = 13;
dbg_bin(mask, 8);  // Shows: [40] mask = 0b0000'1101
```

---

## Choosing the Right Macro - Quick Guide

**Want to print a value?**
- Simple variable → `dbg(x)`
- Inside loop → `dbg_iter(i, x)`
- Conditional → `dbg_if(condition, x)`

**Working with arrays?**
- 1D array → `dbg_arr(arr, n)` or `dbg(vec)`
- 2D array/matrix → `dbg_mat(vec2d)` or `dbg_dp2d(dp)`
- Character grid (maze, board) → `dbg_grid(grid)`
- Subarray [l..r] → `dbg_range(vec, l, r)`

**Working with DP?**
- 1D DP array → `dbg_dp(dp)`
- 2D DP table (no labels) → `dbg_dp2d(dp)`
- 2D DP with meaning (e.g., items vs capacity) → `dbg_dp2d_labeled(dp, "items", "capacity")`

**Working with graphs/trees?**
- Directed graph (adjacency list) → `dbg_graph(adj)`
- Undirected graph → `dbg_ugraph(adj)`
- Binary tree (LeetCode) → `dbg_btree(root)`
- Linked list (LeetCode) → `dbg_list(head)`
- Tree from parent array → `dbg_tree(parent)`

**Bit manipulation?**
- Show bits with fixed width → `dbg_bin(val, 8)`
- Show bits auto-sized → `dbg_bits(val)`

**Organizing output?**
- Mark a section → `dbg_section("title")`

---

## LeetCode Structs

Debug.h auto-detects LeetCode's standard structs:

```cpp
// Linked List (standard LeetCode definition)
struct ListNode {
    int val;
    ListNode* next;
    // ...constructors
};

ListNode* head = new ListNode(1);
head->next = new ListNode(2);
head->next->next = new ListNode(3);

dbg_list(head);  // Output: [1 → 2 → 3 → null]
```

```cpp
// Binary Tree (standard LeetCode definition)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // ...constructors
};

TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);

dbg_btree(root);      // Pretty visual tree
dbg_btree_bfs(root);  // Level-order traversal
```

---

## Runtime Control

**During development (see debug output):**
```bash
make run-debug my_problem              # All debug macros are active
make run-debug my_problem TestCase3    # Debug specific test
```

**Before submission (see clean output):**
```bash
make run my_problem                    # All debug macros are inactive
```

**Extract for submission (automatic):**
```bash
cd src/leetcode && extract my_problem
# → All dbg() calls removed automatically
# → Code is submission-ready
```

**Compile-time disable** (for manual compilation):
```bash
g++ -DNO_DEBUG solution.cpp            # Compile without debug macros
# or
#define NO_DEBUG                       // Add at top of file before #include "Debug.h"
#include "Debug.h"
```
