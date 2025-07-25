/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // return recursion(root);
        return stacking(root);
    }

    // Recursion
    // Time Complexity O(n)
    // Space Complexity O(n) if tree is skewed
    //                  O(log n) if tree is proper binary tree
    int recursion(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max( recursion(root->left), recursion(root->right) );
    }

    // Stack
    // Time Complexity O(n)
    // Space Complexity O(n) if tree is skewed
    //                  O(logn) if proper binary tree
    int stacking(TreeNode* root) {
        vector<pair<int, TreeNode*>> stack;
        stack.push_back({1, root});
        int max_depth = 0;

        while (!stack.empty()) {
            pair<int, TreeNode*> _pair = stack.back();
            stack.pop_back();
            TreeNode* _node = _pair.second;
            int _depth = _pair.first;

            if (_node == nullptr) continue;

            max_depth = max(max_depth, _depth);

            stack.push_back({_depth + 1, _node->left});
            stack.push_back({_depth + 1, _node->right});
        }

        return max_depth;
    }
}