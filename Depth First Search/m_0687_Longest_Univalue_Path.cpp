/*
  給定一二元樹，求simple path length最大值，且該simple path上的元素數字皆相同

  全局res，如果數字相同則皆在一起，否則斷開
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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        function <int(TreeNode*, int)> count = [&] (TreeNode* root, int val) {
            if (!root) return 0;
            int left = count(root->left, root->val);
            int right = count(root->right, root->val);
            res = max(res, left + right);
            return (val == root->val) ? (1 + max(left, right)) : 0;
        };
        count(root, root->val);
        return res;
    }
};
