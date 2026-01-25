#include <iostream>
#include <vector>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// --- Your Solution Class ---
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        bool is_subroot = false;
        dfs(root, subRoot, is_subroot);
        return is_subroot;
    }

    bool check_same_tree(TreeNode *r, TreeNode *q) {
        if (!r && !q) return true;
        if (r && q && r->val == q->val) {
            return check_same_tree(r->left, q->left) &&
                   check_same_tree(r->right, q->right);
        }
        return false;
    }

    void dfs(TreeNode *root, TreeNode* subRoot, bool &is_subroot) {
        if (!root || is_subroot) return;
        
        // Attempt match
        if (subRoot && subRoot->val == root->val) {
            bool match = check_same_tree(root->left, subRoot->left) && 
                         check_same_tree(root->right, subRoot->right);
            if (match) is_subroot = true;
        }
        
        dfs(root->left, subRoot, is_subroot);
        dfs(root->right, subRoot, is_subroot);
    }
};

// --- Helper to build tree from vector (LeetCode style level-order) ---
// Use INT_MIN to represent null in the input vector
TreeNode* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        // Left Child
        if (i < nodes.size() && nodes[i] != -999) { // Using -999 as null placeholder
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        
        // Right Child
        if (i < nodes.size() && nodes[i] != -999) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// --- Helper to clean up memory ---
void deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Solution sol;

    // Test Case Construction
    // root = [1,2,3,4,5,null,null,6]
    // subRoot = [2,4,5]
    // Note: -999 represents 'null'
    std::vector<int> rootVec = {1, 2, 3, 4, 5, -999, -999, 6};
    std::vector<int> subVec = {2, 4, 5};

    TreeNode* root = buildTree(rootVec);
    TreeNode* subRoot = buildTree(subVec);

    std::cout << "Running isSubtree..." << std::endl;
    bool result = sol.isSubtree(root, subRoot);

    std::cout << "Result: " << (result ? "true" : "false") << std::endl;
    std::cout << "Expected: false" << std::endl;

    if (result == false) {
        std::cout << "[PASS] Output matches expectation." << std::endl;
    } else {
        std::cout << "[FAIL] Output does not match expectation." << std::endl;
    }

    // Cleanup
    deleteTree(root);
    deleteTree(subRoot);

    return 0;
}