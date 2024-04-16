/*
  給定一棵完全二元樹，求其節點個數

  因為一棵完全二元樹至少包含一棵滿二元樹，利用這種特性可以將複雜度降至O(lognlogn)
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
    int countNodes(TreeNode* root) {
        TreeNode *l = root, *r = root;
        int hl = 0, hr = 0;
        while (l != nullptr) {
            l = l->left;
            hl++;
        }
        while (r != nullptr) {
            r = r->right;
            hr++;
        }
        if (hl == hr) {
            return (int)pow(2, hl) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
