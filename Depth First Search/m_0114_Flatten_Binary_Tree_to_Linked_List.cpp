/*
  給定一二元樹，將其攤平成右傾斜的鏈結串列，且不可使用額外空間

  根據定義，根先接上左邊攤平後的結果，在接上右邊攤平後的結果，使用遞迴設計
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
    void flatten(TreeNode* root) {
        if (!root) return;

        TreeNode *left = root->left, *right = root->right;
        flatten(root->left);
        flatten(root->right);

        root->left = NULL;
        root->right = left;
        while (root->right) root = root->right;
        root->right = right;
    }
};
