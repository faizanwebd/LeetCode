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
    int maxLen = 0;

    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return;
        maxLen = max(maxLen, length);
        if (isLeft) {
            dfs(node->right, false, length + 1);
            dfs(node->left, true, 1);
        } else {
            dfs(node->left, true, length + 1);
            dfs(node->right, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxLen;
    }
};
