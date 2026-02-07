#ifndef LEETCODECHALLENGES_DEBUG_H
#define LEETCODECHALLENGES_DEBUG_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <utility>
#include <limits>
#include <type_traits>
#include <cstdlib>

// ==================== RUNTIME DEBUG CONTROL ====================
// Check environment variable DEBUG_ENABLED at runtime
inline bool isDebugEnabled() {
    static int enabled = -1; // -1 = not checked, 0 = disabled, 1 = enabled
    if (enabled == -1) {
        const char* env = std::getenv("DEBUG_ENABLED");
        enabled = (env && std::string(env) == "1") ? 1 : 0;
    }
    return enabled == 1;
}

// Conditional output stream - only outputs if debug is enabled
struct ConditionalCerr {
    template<typename T>
    ConditionalCerr& operator<<(const T& val) {
        if (isDebugEnabled()) {
            std::cerr << val;
        }
        return *this;
    }
    // Handle manipulators like std::endl
    ConditionalCerr& operator<<(std::ostream& (*manip)(std::ostream&)) {
        if (isDebugEnabled()) {
            std::cerr << manip;
        }
        return *this;
    }
};

inline ConditionalCerr cdbg;

// ==================== COLOR CODES ====================
#ifdef NO_COLOR
    #define C_RESET   ""
    #define C_CYAN    ""
    #define C_YELLOW  ""
    #define C_GREEN   ""
    #define C_RED     ""
    #define C_MAGENTA ""
    #define C_BLUE    ""
    #define C_DIM     ""
#else
    #define C_RESET   "\033[0m"
    #define C_CYAN    "\033[36m"
    #define C_YELLOW  "\033[33m"
    #define C_GREEN   "\033[32m"
    #define C_RED     "\033[31m"
    #define C_MAGENTA "\033[35m"
    #define C_BLUE    "\033[34m"
    #define C_DIM     "\033[2m"
#endif

// ==================== FORWARD DECLARATIONS ====================
template<typename T> std::string dbgStr(const T& x);
template<typename T> std::string dbgStr(const std::vector<T>& v);
template<typename T, typename U> std::string dbgStr(const std::pair<T, U>& p);

// ==================== BASIC TYPES ====================
template<typename T>
std::string dbgStr(const T& x) {
    std::ostringstream oss;
    oss << x;
    return oss.str();
}

inline std::string dbgStr(const std::string& s) {
    return "\"" + s + "\"";
}

inline std::string dbgStr(const char* s) {
    return s ? ("\"" + std::string(s) + "\"") : "nullptr";
}

inline std::string dbgStr(char c) {
    return std::string("'") + c + "'";
}

inline std::string dbgStr(bool b) {
    return b ? "true" : "false";
}

// ==================== PAIR ====================
template<typename T, typename U>
std::string dbgStr(const std::pair<T, U>& p) {
    return "(" + dbgStr(p.first) + ", " + dbgStr(p.second) + ")";
}

// ==================== LINKED LIST NODE SUPPORT ====================
// Common LeetCode-style ListNode
// Define your ListNode with: struct ListNode { int val; ListNode* next; };
// Or use these type traits to auto-detect linked list nodes

// Type trait to detect if T has 'val' and 'next' members (linked list pattern)
template<typename T, typename = void>
struct is_list_node : std::false_type {};

template<typename T>
struct is_list_node<T, std::void_t<
    decltype(std::declval<T>().val),
    decltype(std::declval<T>().next)
>> : std::true_type {};

// Debug linked list from pointer
template<typename T>
typename std::enable_if<is_list_node<T>::value, std::string>::type
dbgStr(T* head) {
    if (!head) return "nullptr";
    std::ostringstream oss;
    oss << "[";
    T* curr = head;
    int count = 0;
    const int maxNodes = 20; // prevent infinite loops
    while (curr && count < maxNodes) {
        if (count > 0) oss << " → ";
        oss << curr->val;
        curr = curr->next;
        count++;
    }
    if (curr) oss << " → ...";
    oss << "]";
    return oss.str();
}

// Macro to debug linked list
#define dbg_list(head) \
    do { if (isDebugEnabled()) { \
        std::cerr << C_CYAN << "[" << __LINE__ << "] " << C_YELLOW << #head << C_RESET << " = " \
                  << C_GREEN << dbgStr(head) << C_RESET << std::endl; \
    } } while(0)

// ==================== BINARY TREE NODE SUPPORT ====================
// Common LeetCode-style TreeNode
// Define your TreeNode with: struct TreeNode { int val; TreeNode *left, *right; };

// Type trait to detect if T has 'val', 'left', 'right' members (binary tree pattern)
template<typename T, typename = void>
struct is_tree_node : std::false_type {};

template<typename T>
struct is_tree_node<T, std::void_t<
    decltype(std::declval<T>().val),
    decltype(std::declval<T>().left),
    decltype(std::declval<T>().right)
>> : std::true_type {};

// Helper to print tree structure
template<typename T>
typename std::enable_if<is_tree_node<T>::value>::type
dbgTreeHelper(T* node, std::string prefix, bool isLeft, std::ostream& os) {
    if (!node) return;

    os << prefix;
    os << (isLeft ? "├── " : "└── ");
    os << C_GREEN << node->val << C_RESET << std::endl;

    std::string newPrefix = prefix + (isLeft ? "│   " : "    ");
    if (node->left || node->right) {
        if (node->left) {
            dbgTreeHelper(node->left, newPrefix, true, os);
        } else if (node->right) {
            os << newPrefix << "├── " << C_DIM << "null" << C_RESET << std::endl;
        }
        if (node->right) {
            dbgTreeHelper(node->right, newPrefix, false, os);
        } else if (node->left) {
            os << newPrefix << "└── " << C_DIM << "null" << C_RESET << std::endl;
        }
    }
}

// Debug binary tree from pointer
template<typename T>
typename std::enable_if<is_tree_node<T>::value, std::string>::type
dbgStr(T* root) {
    if (!root) return "nullptr";
    std::ostringstream oss;
    oss << C_GREEN << root->val << C_RESET << std::endl;
    std::string prefix = "";
    if (root->left || root->right) {
        if (root->left) {
            dbgTreeHelper(root->left, prefix, true, oss);
        } else {
            oss << prefix << "├── " << C_DIM << "null" << C_RESET << std::endl;
        }
        if (root->right) {
            dbgTreeHelper(root->right, prefix, false, oss);
        } else {
            oss << prefix << "└── " << C_DIM << "null" << C_RESET << std::endl;
        }
    }
    return oss.str();
}

// Macro to debug binary tree
#define dbg_btree(root) \
    do { if (isDebugEnabled()) { \
        std::cerr << C_CYAN << "[" << __LINE__ << "] " << C_YELLOW << #root << C_RESET << ":" << std::endl; \
        if (root) { \
            std::cerr << dbgStr(root); \
        } else { \
            std::cerr << C_DIM << "nullptr" << C_RESET << std::endl; \
        } \
    } } while(0)

// Level-order (BFS) representation of binary tree
template<typename T>
typename std::enable_if<is_tree_node<T>::value>::type
dbgTreeBFS(const std::string& name, T* root, int line) {
    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET << " (level-order) = [";
    if (!root) {
        std::cerr << "]" << std::endl;
        return;
    }
    std::queue<T*> q;
    q.push(root);
    bool first = true;
    int nullCount = 0;
    while (!q.empty()) {
        T* node = q.front();
        q.pop();
        if (!first) std::cerr << ", ";
        first = false;
        if (node) {
            // Print accumulated nulls
            std::cerr << C_GREEN << node->val << C_RESET;
            q.push(node->left);
            q.push(node->right);
        } else {
            std::cerr << C_DIM << "null" << C_RESET;
        }
    }
    std::cerr << "]" << std::endl;
}

#define dbg_btree_bfs(root) \
    do { if (isDebugEnabled()) { dbgTreeBFS(#root, root, __LINE__); } } while(0)

// ==================== VECTOR ====================
template<typename T>
std::string dbgStr(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) oss << ", ";
        oss << dbgStr(v[i]);
    }
    oss << "]";
    return oss.str();
}

// ==================== DEQUE ====================
template<typename T>
std::string dbgStr(const std::deque<T>& d) {
    std::ostringstream oss;
    oss << "deque[";
    bool first = true;
    for (const auto& x : d) {
        if (!first) oss << ", ";
        first = false;
        oss << dbgStr(x);
    }
    oss << "]";
    return oss.str();
}

// ==================== SET / MULTISET ====================
template<typename T>
std::string dbgStr(const std::set<T>& s) {
    std::ostringstream oss;
    oss << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) oss << ", ";
        first = false;
        oss << dbgStr(x);
    }
    oss << "}";
    return oss.str();
}

template<typename T>
std::string dbgStr(const std::multiset<T>& s) {
    std::ostringstream oss;
    oss << "multiset{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) oss << ", ";
        first = false;
        oss << dbgStr(x);
    }
    oss << "}";
    return oss.str();
}

template<typename T>
std::string dbgStr(const std::unordered_set<T>& s) {
    std::ostringstream oss;
    oss << "uset{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) oss << ", ";
        first = false;
        oss << dbgStr(x);
    }
    oss << "}";
    return oss.str();
}

// ==================== MAP ====================
template<typename K, typename V>
std::string dbgStr(const std::map<K, V>& m) {
    std::ostringstream oss;
    oss << "{";
    bool first = true;
    for (const auto& [k, v] : m) {
        if (!first) oss << ", ";
        first = false;
        oss << dbgStr(k) << ": " << dbgStr(v);
    }
    oss << "}";
    return oss.str();
}

template<typename K, typename V>
std::string dbgStr(const std::unordered_map<K, V>& m) {
    std::ostringstream oss;
    oss << "umap{";
    bool first = true;
    for (const auto& [k, v] : m) {
        if (!first) oss << ", ";
        first = false;
        oss << dbgStr(k) << ": " << dbgStr(v);
    }
    oss << "}";
    return oss.str();
}

// ==================== QUEUE / PRIORITY_QUEUE / STACK ====================
template<typename T>
std::string dbgStr(std::queue<T> q) { // copy intentional
    std::ostringstream oss;
    oss << "queue[front→";
    bool first = true;
    while (!q.empty()) {
        if (!first) oss << ", ";
        first = false;
        oss << dbgStr(q.front());
        q.pop();
    }
    oss << "←back]";
    return oss.str();
}

template<typename T, typename C, typename Cmp>
std::string dbgStr(std::priority_queue<T, C, Cmp> pq) { // copy intentional
    std::ostringstream oss;
    oss << "pq[top→";
    bool first = true;
    while (!pq.empty()) {
        if (!first) oss << ", ";
        first = false;
        oss << dbgStr(pq.top());
        pq.pop();
    }
    oss << "]";
    return oss.str();
}

template<typename T>
std::string dbgStr(std::stack<T> st) { // copy intentional
    std::ostringstream oss;
    std::vector<T> items;
    while (!st.empty()) {
        items.push_back(st.top());
        st.pop();
    }
    oss << "stack[top→";
    for (size_t i = 0; i < items.size(); i++) {
        if (i > 0) oss << ", ";
        oss << dbgStr(items[i]);
    }
    oss << "←bottom]";
    return oss.str();
}

// ==================== CORE DEBUG FUNCTION ====================
inline void dbgPrint() { std::cerr << std::endl; }

template<typename T, typename... Args>
void dbgPrint(const T& first, const Args&... rest) {
    std::cerr << dbgStr(first);
    if constexpr (sizeof...(rest) > 0) {
        std::cerr << ", ";
        dbgPrint(rest...);
    } else {
        std::cerr << std::endl;
    }
}

// ==================== MAIN DEBUG MACRO ====================
#define dbg(...) \
    do { if (isDebugEnabled()) { \
        std::cerr << C_CYAN << "[" << __LINE__ << "] " << C_YELLOW << #__VA_ARGS__ << C_RESET << " = "; \
        dbgPrint(__VA_ARGS__); \
    } } while(0)

// ==================== ARRAY DEBUG (C-style) ====================
template<typename T>
void dbgArray(const std::string& name, const T* arr, size_t n, int line) {
    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET << " = [";
    for (size_t i = 0; i < n; i++) {
        if (i > 0) std::cerr << ", ";
        std::cerr << C_GREEN << arr[i] << C_RESET;
    }
    std::cerr << "]" << std::endl;
}

#define dbg_arr(arr, n) \
    do { if (isDebugEnabled()) { dbgArray(#arr, arr, n, __LINE__); } } while(0)

// ==================== 2D MATRIX DEBUG ====================
template<typename T>
void dbgMatrix(const std::string& name, const std::vector<std::vector<T>>& mat, int line) {
    size_t rows = mat.size();
    size_t cols = rows > 0 ? mat[0].size() : 0;

    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET
              << " (" << rows << "×" << cols << "):" << std::endl;

    // Find max width for alignment
    int maxW = 1;
    for (const auto& row : mat) {
        for (const auto& val : row) {
            int w = dbgStr(val).length();
            maxW = std::max(maxW, w);
        }
    }
    // Consider column index width
    for (size_t j = 0; j < cols; j++) {
        maxW = std::max(maxW, (int)std::to_string(j).length());
    }

    // Calculate row index width
    int rowIdxW = rows > 0 ? (int)std::to_string(rows - 1).length() : 1;
    rowIdxW = std::max(rowIdxW, 2);

    // Print column header with row/col indices
    std::cerr << C_DIM << std::string(rowIdxW + 2, ' ');
    for (size_t j = 0; j < cols; j++) {
        std::cerr << std::setw(maxW + 1) << j;
    }
    std::cerr << C_RESET << std::endl;

    for (size_t i = 0; i < rows; i++) {
        std::cerr << C_DIM << std::setw(rowIdxW) << i << C_RESET << " [";
        for (size_t j = 0; j < mat[i].size(); j++) {
            if (j > 0) std::cerr << ",";
            std::cerr << C_GREEN << std::setw(maxW) << mat[i][j] << C_RESET;
        }
        std::cerr << "]" << std::endl;
    }
}

#define dbg_mat(mat) \
    do { if (isDebugEnabled()) { dbgMatrix(#mat, mat, __LINE__); } } while(0)

// ==================== 2D C-STYLE ARRAY DEBUG ====================
template<typename T, size_t R, size_t C>
void dbgMatrix2D(const std::string& name, T (&arr)[R][C], int line) {
    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET
              << " (" << R << "×" << C << "):" << std::endl;

    int maxW = 1;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            int w = dbgStr(arr[i][j]).length();
            maxW = std::max(maxW, w);
        }
    }
    // Consider column index width
    for (size_t j = 0; j < C; j++) {
        maxW = std::max(maxW, (int)std::to_string(j).length());
    }

    // Calculate row index width
    int rowIdxW = R > 0 ? (int)std::to_string(R - 1).length() : 1;
    rowIdxW = std::max(rowIdxW, 2);

    std::cerr << C_DIM << std::string(rowIdxW + 2, ' ');
    for (size_t j = 0; j < C; j++) {
        std::cerr << std::setw(maxW + 1) << j;
    }
    std::cerr << C_RESET << std::endl;

    for (size_t i = 0; i < R; i++) {
        std::cerr << C_DIM << std::setw(rowIdxW) << i << C_RESET << " [";
        for (size_t j = 0; j < C; j++) {
            if (j > 0) std::cerr << ",";
            std::cerr << C_GREEN << std::setw(maxW) << arr[i][j] << C_RESET;
        }
        std::cerr << "]" << std::endl;
    }
}

#define dbg_mat2d(arr) \
    do { if (isDebugEnabled()) { dbgMatrix2D(#arr, arr, __LINE__); } } while(0)

// ==================== GRAPH ADJACENCY LIST DEBUG ====================
template<typename T>
void dbgGraph(const std::string& name, const std::vector<std::vector<T>>& adj, int line, bool directed = true) {
    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET
              << " (" << (directed ? "directed" : "undirected") << ", " << adj.size() << " nodes):" << std::endl;

    for (size_t i = 0; i < adj.size(); i++) {
        if (adj[i].empty()) continue;
        std::cerr << "  " << C_BLUE << i << C_RESET << " → ";
        for (size_t j = 0; j < adj[i].size(); j++) {
            if (j > 0) std::cerr << ", ";
            std::cerr << C_GREEN << adj[i][j] << C_RESET;
        }
        std::cerr << std::endl;
    }
}

#define dbg_graph(adj) \
    do { if (isDebugEnabled()) { dbgGraph(#adj, adj, __LINE__, true); } } while(0)
#define dbg_ugraph(adj) \
    do { if (isDebugEnabled()) { dbgGraph(#adj, adj, __LINE__, false); } } while(0)

// ==================== GRID/BOARD DEBUG (for char grids) ====================
inline void dbgGrid(const std::string& name, const std::vector<std::string>& grid, int line) {
    size_t rows = grid.size();
    size_t cols = rows > 0 ? grid[0].size() : 0;

    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET
              << " (" << rows << "×" << cols << "):" << std::endl;

    // Column indices
    std::cerr << C_DIM << "   ";
    for (size_t j = 0; j < cols; j++) {
        std::cerr << (j % 10);
    }
    std::cerr << C_RESET << std::endl;

    for (size_t i = 0; i < rows; i++) {
        std::cerr << C_DIM << std::setw(2) << i << C_RESET << " ";
        for (char c : grid[i]) {
            if (c == '#' || c == '*') {
                std::cerr << C_RED << c << C_RESET;
            } else if (c == '.' || c == ' ') {
                std::cerr << C_DIM << c << C_RESET;
            } else {
                std::cerr << C_GREEN << c << C_RESET;
            }
        }
        std::cerr << std::endl;
    }
}

#define dbg_grid(grid) \
    do { if (isDebugEnabled()) { dbgGrid(#grid, grid, __LINE__); } } while(0)

// ==================== 1D DP TABLE DEBUG ====================
template<typename T>
void dbgDP(const std::string& name, const std::vector<T>& dp, int line,
           const std::string& indexLabel = "i") {
    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET
              << " (size=" << dp.size() << "):" << std::endl;

    // Find max width needed for values and indices
    int maxW = 2;
    for (size_t i = 0; i < dp.size(); i++) {
        std::ostringstream oss;
        oss << dp[i];
        maxW = std::max(maxW, (int)oss.str().length());
        maxW = std::max(maxW, (int)std::to_string(i).length());
    }

    // Label width
    int labelW = std::max((int)indexLabel.length(), 2);

    std::cerr << C_DIM << std::setw(labelW) << indexLabel << ": " << C_RESET;
    for (size_t i = 0; i < dp.size(); i++) {
        std::cerr << std::setw(maxW + 1) << i;
    }
    std::cerr << std::endl;
    std::cerr << std::setw(labelW) << "dp" << ": ";
    for (size_t i = 0; i < dp.size(); i++) {
        std::cerr << C_GREEN << std::setw(maxW + 1) << dp[i] << C_RESET;
    }
    std::cerr << std::endl;
}

#define dbg_dp(dp) \
    do { if (isDebugEnabled()) { dbgDP(#dp, dp, __LINE__); } } while(0)

// ==================== 2D DP TABLE DEBUG ====================
template<typename T>
void dbgDP2D(const std::string& name, const std::vector<std::vector<T>>& dp, int line,
             const std::string& rowLabel = "i", const std::string& colLabel = "j") {
    size_t rows = dp.size();
    size_t cols = rows > 0 ? dp[0].size() : 0;

    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET
              << " (" << rows << "×" << cols << ") [" << rowLabel << "][" << colLabel << "]:" << std::endl;

    // Find max width for data values and column indices
    int maxW = 1;
    for (const auto& row : dp) {
        for (const auto& val : row) {
            std::ostringstream oss;
            oss << val;
            maxW = std::max(maxW, (int)oss.str().length());
        }
    }
    // Also consider column index width
    for (size_t j = 0; j < cols; j++) {
        maxW = std::max(maxW, (int)std::to_string(j).length());
    }
    maxW = std::max(maxW, 2); // minimum width

    // Calculate row label width: max of rowLabel length and largest row index
    int maxRowIdx = rows > 0 ? (int)std::to_string(rows - 1).length() : 1;
    int rowLabelW = std::max((int)rowLabel.length(), maxRowIdx);

    // Header label is "rowLabel\colLabel" - calculate its total width
    std::string headerLabel = rowLabel + "\\" + colLabel;
    int headerLabelW = (int)headerLabel.length();
    // The first column width should accommodate both the header label and row indices
    int firstColW = std::max(headerLabelW, rowLabelW);

    // Column header with proper alignment
    std::cerr << C_DIM << std::setw(firstColW) << headerLabel << " ";
    for (size_t j = 0; j < cols; j++) {
        std::cerr << std::setw(maxW + 1) << j;
    }
    std::cerr << C_RESET << std::endl;

    // Separator line
    std::cerr << C_DIM << std::string(static_cast<size_t>(firstColW), ' ') << " +" << std::string(static_cast<size_t>((maxW + 1)) * cols, '-') << C_RESET << std::endl;

    // Data rows
    for (size_t i = 0; i < rows; i++) {
        std::cerr << C_DIM << std::setw(firstColW) << i << C_RESET << " |";
        for (size_t j = 0; j < dp[i].size(); j++) {
            T val = dp[i][j];
            bool isDefault = (val == T{} || val == std::numeric_limits<T>::max() ||
                            val == std::numeric_limits<T>::min());
            if (isDefault) {
                std::cerr << C_DIM << std::setw(maxW + 1) << val << C_RESET;
            } else {
                std::cerr << C_GREEN << std::setw(maxW + 1) << val << C_RESET;
            }
        }
        std::cerr << std::endl;
    }
}

// 2D C-style array version for DP
template<typename T, size_t R, size_t C>
void dbgDP2D(const std::string& name, T (&dp)[R][C], int line,
             const std::string& rowLabel = "i", const std::string& colLabel = "j") {
    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET
              << " (" << R << "×" << C << ") [" << rowLabel << "][" << colLabel << "]:" << std::endl;

    // Find max width
    int maxW = 2;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            std::ostringstream oss;
            oss << dp[i][j];
            maxW = std::max(maxW, (int)oss.str().length());
        }
    }
    for (size_t j = 0; j < C; j++) {
        maxW = std::max(maxW, (int)std::to_string(j).length());
    }

    // Calculate row label width: max of rowLabel length and largest row index
    int maxRowIdx = R > 0 ? (int)std::to_string(R - 1).length() : 1;
    int rowLabelW = std::max((int)rowLabel.length(), maxRowIdx);

    // Header label is "rowLabel\colLabel" - calculate its total width
    std::string headerLabel = rowLabel + "\\" + colLabel;
    int headerLabelW = (int)headerLabel.length();
    // The first column width should accommodate both the header label and row indices
    int firstColW = std::max(headerLabelW, rowLabelW);

    // Column header
    std::cerr << C_DIM << std::setw(firstColW) << headerLabel << " ";
    for (size_t j = 0; j < C; j++) {
        std::cerr << std::setw(maxW + 1) << j;
    }
    std::cerr << C_RESET << std::endl;

    // Separator
    std::cerr << C_DIM << std::string(static_cast<size_t>(firstColW), ' ') << " +" << std::string(static_cast<size_t>((maxW + 1)) * C, '-') << C_RESET << std::endl;

    // Data
    for (size_t i = 0; i < R; i++) {
        std::cerr << C_DIM << std::setw(firstColW) << i << C_RESET << " |";
        for (size_t j = 0; j < C; j++) {
            T val = dp[i][j];
            bool isDefault = (val == T{});
            if (isDefault) {
                std::cerr << C_DIM << std::setw(maxW + 1) << val << C_RESET;
            } else {
                std::cerr << C_GREEN << std::setw(maxW + 1) << val << C_RESET;
            }
        }
        std::cerr << std::endl;
    }
}

#define dbg_dp2d(dp) \
    do { if (isDebugEnabled()) { dbgDP2D(#dp, dp, __LINE__); } } while(0)
#define dbg_dp2d_labeled(dp, rowLabel, colLabel) \
    do { if (isDebugEnabled()) { dbgDP2D(#dp, dp, __LINE__, rowLabel, colLabel); } } while(0)

// ==================== SECTION SEPARATOR ====================
#define dbg_section(title) \
    do { if (isDebugEnabled()) { \
        std::cerr << C_MAGENTA << "\n══════════ " << title << " ══════════" << C_RESET << std::endl; \
    } } while(0)

// ==================== ITERATION MARKER ====================
#define dbg_iter(i, ...) \
    do { if (isDebugEnabled()) { \
        std::cerr << C_CYAN << "[" << __LINE__ << "] " << C_BLUE << "iter " << i << C_RESET << ": "; \
        dbgPrint(__VA_ARGS__); \
    } } while(0)

// ==================== CONDITIONAL DEBUG ====================
#define dbg_if(cond, ...) \
    do { if (isDebugEnabled() && (cond)) { dbg(__VA_ARGS__); } } while(0)

// ==================== BINARY REPRESENTATION ====================
template<typename T>
void dbgBinary(const std::string& name, T val, int bits, int line) {
    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET
              << " = " << val << " = " << C_GREEN << "0b";
    for (int i = bits - 1; i >= 0; i--) {
        std::cerr << ((val >> i) & 1);
        if (i > 0 && i % 4 == 0) std::cerr << "'";
    }
    std::cerr << C_RESET << std::endl;
}

#define dbg_bin(val, bits) \
    do { if (isDebugEnabled()) { dbgBinary(#val, val, bits, __LINE__); } } while(0)
#define dbg_bits(val) \
    do { if (isDebugEnabled()) { dbgBinary(#val, val, sizeof(val) * 8, __LINE__); } } while(0)

// ==================== RANGE DEBUG (for debugging subarray/substring) ====================
template<typename T>
void dbgRange(const std::string& name, const std::vector<T>& v, size_t l, size_t r, int line) {
    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << "[" << l << ".." << r << "]"
              << C_RESET << " = [";
    for (size_t i = l; i <= r && i < v.size(); i++) {
        if (i > l) std::cerr << ", ";
        std::cerr << C_GREEN << v[i] << C_RESET;
    }
    std::cerr << "]" << std::endl;
}

#define dbg_range(v, l, r) \
    do { if (isDebugEnabled()) { dbgRange(#v, v, l, r, __LINE__); } } while(0)

// ==================== TREE DEBUG (parent array representation) ====================
template<typename T>
void dbgTree(const std::string& name, const std::vector<T>& parent, int line) {
    std::cerr << C_CYAN << "[" << line << "] " << C_YELLOW << name << C_RESET
              << " (tree, " << parent.size() << " nodes):" << std::endl;

    for (size_t i = 0; i < parent.size(); i++) {
        if (parent[i] == static_cast<T>(-1) || parent[i] < 0) {
            std::cerr << "  " << C_GREEN << i << C_RESET << " (root)" << std::endl;
        } else {
            std::cerr << "  " << C_GREEN << i << C_RESET << " ← " << C_BLUE << parent[i] << C_RESET << std::endl;
        }
    }
}

#define dbg_tree(parent) \
    do { if (isDebugEnabled()) { dbgTree(#parent, parent, __LINE__); } } while(0)

// ==================== DISABLE ALL DEBUG FOR SUBMISSION ====================
// To disable: compile with -DNO_DEBUG or just remove the include
#ifdef NO_DEBUG
    #undef dbg
    #undef dbg_arr
    #undef dbg_mat
    #undef dbg_mat2d
    #undef dbg_graph
    #undef dbg_ugraph
    #undef dbg_grid
    #undef dbg_dp
    #undef dbg_dp2d
    #undef dbg_dp2d_labeled
    #undef dbg_section
    #undef dbg_iter
    #undef dbg_if
    #undef dbg_bin
    #undef dbg_bits
    #undef dbg_range
    #undef dbg_tree
    #undef dbg_list
    #undef dbg_btree
    #undef dbg_btree_bfs

    #define dbg(...) ((void)0)
    #define dbg_arr(arr, n) ((void)0)
    #define dbg_mat(mat) ((void)0)
    #define dbg_mat2d(arr) ((void)0)
    #define dbg_graph(adj) ((void)0)
    #define dbg_ugraph(adj) ((void)0)
    #define dbg_grid(grid) ((void)0)
    #define dbg_dp(dp) ((void)0)
    #define dbg_dp2d(dp) ((void)0)
    #define dbg_dp2d_labeled(dp, r, c) ((void)0)
    #define dbg_section(title) ((void)0)
    #define dbg_iter(i, ...) ((void)0)
    #define dbg_if(cond, ...) ((void)0)
    #define dbg_bin(val, bits) ((void)0)
    #define dbg_bits(val) ((void)0)
    #define dbg_range(v, l, r) ((void)0)
    #define dbg_tree(parent) ((void)0)
    #define dbg_list(head) ((void)0)
    #define dbg_btree(root) ((void)0)
    #define dbg_btree_bfs(root) ((void)0)
#endif

#endif // LEETCODECHALLENGES_DEBUG_H
