/*
  給定一樹根，求其是否為二元搜尋樹

  若中序走訪非由小排到大或由大排到小，則代表該樹非二元搜尋樹
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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        stack<TreeNode*> s;
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top(); s.pop();
            if (prev && prev->val >= curr->val) return false;
            prev = curr;
            curr = curr->right;
        }
        return true;
    }
};
