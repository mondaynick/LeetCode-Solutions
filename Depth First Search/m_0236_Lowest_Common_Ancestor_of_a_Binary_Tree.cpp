/*
  給定一棵樹及兩個節點，回傳兩個節點的最低共同祖先(即從哪個節點分裂出來的，兩個節點也可能其一是祖先)

  先看左邊有沒有存在p或q、右邊有沒有存在p或q、最後看目前的值有沒有等於p或q，往下遞迴，若往下不存在p或q其中之一則不需要繼續展開
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        function<bool(TreeNode*, TreeNode*, TreeNode*)> dfs = [&] (TreeNode* n, TreeNode* n1, TreeNode* n2) {
            if (!n) return false;
            int left = dfs(n->left, n1, n2) ? 1 : 0;
            int right = dfs(n->right, n1, n2) ? 1 : 0;
            int mid = (n->val == n1->val || n->val == n2->val) ? 1 : 0;
            if (left + right + mid == 2) res = n;
            return (left + right + mid > 0);
        };
        dfs(root, p, q);
        return res;
    }
};
