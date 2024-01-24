/*
  給定兩個樹根，判斷兩個樹是否相同

  利用遞迴比較
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (NULL == p && NULL == q) return true;
        if (NULL != p && NULL != q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return true;
        return false;
    }
};
