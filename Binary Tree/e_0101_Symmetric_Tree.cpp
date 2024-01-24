/*
  給定一樹根，判斷該數是否為對稱

  根據定義
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
    bool isSymmetric(TreeNode* root) {
        if (NULL == root) return true;
        queue <TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* leftNode = q.front(); q.pop();
            TreeNode* rightNode = q.front(); q.pop();
            if (NULL == leftNode && NULL == rightNode) continue;
            if (NULL != leftNode && NULL != rightNode && leftNode->val == rightNode->val) {
                q.push(leftNode->left);
                q.push(rightNode->right);
                q.push(leftNode->right);
                q.push(rightNode->left);
            } else {
                return false;
            }
        }
        return true;
    }
};
