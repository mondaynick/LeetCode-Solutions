/*
  給定一二元樹及targetSum，回傳從root到leaf的simple path其上所有節點之和等於targetSum之所有可能性

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
    vector<vector<int>> res;
    void dfs(TreeNode* root, int targetSum, int curr, vector<int> temp) {
        if (!root) return;

        curr += root->val;
        temp.push_back(root->val);

        if (!root->left && !root->right && curr == targetSum) {
            res.push_back(temp);
        } else {
            dfs(root->left , targetSum, curr, temp);
            dfs(root->right, targetSum, curr, temp);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0, {});
        return res;
    }
};
