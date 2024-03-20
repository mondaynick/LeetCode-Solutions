/*
  給定一二元樹及targetSum，若存在一個從root到leaf的simple path其上所有節點之和等於targetSum則回傳true，反之則回傳false

  利用dfs
 */

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
    bool hasPathSum(TreeNode* root, int targetSum, int curr = 0) {
        if (!root) return false;

        curr += root->val;
        if (!root->left && !root->right && curr == targetSum) return true;
        return hasPathSum(root->left, targetSum, curr) || hasPathSum(root->right, targetSum, curr);
    }
};
