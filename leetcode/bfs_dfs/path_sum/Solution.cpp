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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return dfs(root, 0, targetSum); 
    }

    bool dfs(TreeNode* root, int currSum, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        currSum += root->val;
        if ( root->left == nullptr && root->right == nullptr ) {
            return currSum == targetSum;
        }
        return dfs(root->left, currSum, targetSum) | dfs(root->right, currSum, targetSum);
    }
}