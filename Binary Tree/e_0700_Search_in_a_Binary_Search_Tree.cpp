/*
  給定一樹根，找出val是否存在並回傳該節點

  根據二元搜尋樹的特性
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        TreeNode* curr = root;
        while (curr) {
            if (val == curr->val) {
                return curr;   
            } else if (val < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return NULL;
    }
};
