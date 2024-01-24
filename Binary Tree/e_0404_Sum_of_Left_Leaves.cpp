/*
  給定一樹根，回傳其滿足葉節點且為左節點的所有節點之和

  再往下遞迴時，傳入為左節點還是右節點
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
    void handler(TreeNode* root, bool isLeft, int& res) {
        if (!root) return;
        if (isLeft && !root->left && !root->right) res += root->val;
        handler(root->left, true, res);
        handler(root->right, false, res);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        handler(root, false, res);
        return res;
    }
};
