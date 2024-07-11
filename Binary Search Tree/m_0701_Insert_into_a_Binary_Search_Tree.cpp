/*
  給定一棵二元搜尋樹，新增其節點

  根據二元搜尋樹特性
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        if (!root) {
            return temp;
        } else {
            TreeNode* curr = root;
            while (1) {
                if (val < curr->val) {
                    if (curr->left) {
                        curr = curr->left;
                    } else {
                        curr->left = temp;
                        return root;
                    }
                } else {
                    if (curr->right) {
                        curr = curr->right;
                    } else {
                        curr->right = temp;
                        return root;
                    }
                }
            }
        }
    }
};
