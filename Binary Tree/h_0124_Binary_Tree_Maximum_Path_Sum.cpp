/*
  給定一樹根，輸出一simple path其元素上之和為最大

  比較當前節點、當前節點+左子節點、當前節點+右子節點、當前節點+左子節點+右子節點四種誰比較大
  其中當前節點+左子節點+右子節點不能往上傳，會破壞simple path的特性
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
    int dfs(TreeNode* root, int& result) {
        int l = (root->left) ? (dfs(root->left, result)) : 0;
        int r = (root->right) ? (dfs(root->right, result)) : 0;
        int m = max(root->val, root->val + max(l,r));
        result = max(max(result, m), root->val + l + r);
        return m;
    }
    int maxPathSum(TreeNode* root) {
        int result = root->val;
        dfs(root, result);
        return result;
    }
};
