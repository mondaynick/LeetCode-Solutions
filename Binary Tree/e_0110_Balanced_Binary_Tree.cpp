/*
  給定一樹根，判斷該數是否平衡

  遞迴呼叫
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
    int getHeight(TreeNode* root) {
        if (NULL == root) return 0;
        int left = getHeight(root->left), right = getHeight(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};
