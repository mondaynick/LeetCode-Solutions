/*
    給定兩棵二元樹，合併成一棵二元樹，即原本位置有1和2則會變成3

    利用bfs對整棵樹做尋訪
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        queue<TreeNode*> s;
        s.push(root1);
        s.push(root2);
        while (!s.empty()) {
            TreeNode* t0 = s.front(); s.pop();
            TreeNode* t1 = s.front(); s.pop();
            if (!t1) continue;
            t0->val += t1->val;
            if (t0->left) {
                s.push(t0->left);
                s.push(t1->left);
            } else {
                t0->left = t1->left;
            }
            if (t0->right) {
                s.push(t0->right);
                s.push(t1->right);
            } else {
                t0->right = t1->right;
            }
        }
        return root1;
    }
};
