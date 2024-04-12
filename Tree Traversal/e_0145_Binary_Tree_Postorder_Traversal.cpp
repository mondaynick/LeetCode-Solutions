/*
  給定一樹根，求postorder traversal

  L -> R -> V
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* curr = s.top();
            if (!curr->left && !curr->right) {
                s.pop();
                res.push_back(curr->val);
            }
            if (curr->right) {
                s.push(curr->right);
                curr->right = NULL;
            }
            if (curr->left) {
                s.push(curr->left);
                curr->left = NULL;
            }
        }
        return res;
    }
};
