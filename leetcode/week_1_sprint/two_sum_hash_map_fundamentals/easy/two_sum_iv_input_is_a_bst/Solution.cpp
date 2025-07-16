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
    bool findTarget(TreeNode* root, int k) {
        // HashSet + DFS
        // Time Complexity O(n)
        // Space Complexity O(n)
        // return approach_1(root, k);

        // HashSet + BFS
        // Time Complexity O(n)
        // Space Complexity O(n)
        // return approach_2(root, k);

        // BST in-order traversal
        // Time Complexity O(n)
        // Space Complexity O(n)
        return approach_3(root, k);
    }

    bool approach_1(TreeNode* root, int k) {
        std::unordered_set<int> uset;

        std::function<bool(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) {
                return false;
            }
            int complement = k - node->val;

            if (uset.count(complement) == 1) {
                return true;
            }
            uset.insert(node->val);

            return dfs(node->left) || dfs(node->right);
        };

        return dfs(root);
    }

    bool approach_2(TreeNode* root, int k) {
        std::unordered_set<int> uset;
        std::deque<TreeNode*> dque;

        dque.push_back(root);

        while (!dque.empty()) {
            TreeNode* node = dque.front();
            dque.pop_front();
            if (node == nullptr) {
                continue;
            }

            int complement = k - node->val;
            if (uset.count(complement) == 1) {
                return true;
            }

            uset.insert(node->val);

            dque.push_back(node->left);
            dque.push_back(node->right);
        }

        return false;
    }

    bool approach_3(TreeNode* root, int k) {
        std::vector<int> v;

        std::function<void(TreeNode*)> in_order = [&](TreeNode* node) {
            if (node == nullptr) return;

            in_order(node->left);
            v.push_back(node->val);
            in_order(node->right);
        };

        in_order(root);

        int low = 0;
        int high = v.size() - 1;

        while (low < high) {
            int sum = v[low] + v[high];
            if (sum == k) {
                return true;
            }

            if (sum > k) {
                --high;
            }

            else {
                ++low;
            }
        }

        return false;

    }
}