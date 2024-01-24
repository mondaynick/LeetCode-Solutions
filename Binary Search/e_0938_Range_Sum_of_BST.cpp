/*
  給定一樹根、low和high，回傳該樹中滿足大於等於low又小於等於high之元素和

  根據二元搜尋樹定義
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int rangeSum = 0;
        if (root->val >= low && root->val <= high)
            rangeSum += root->val;
        rangeSum += rangeSumBST(root->left, low, high);
        rangeSum += rangeSumBST(root->right, low, high);
        return rangeSum;
    }
};
