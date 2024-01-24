/*
  給定所有住家的價值且住加呈二元樹狀，若一個晚上有連續兩間被偷會觸發警報，輸出再不觸發警報的情況下最多可以偷多少

  若偷當前節點，則其父節點與子節點不可以偷，若不偷當前節點，則其父節點與子節點可以偷
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
    unordered_map<TreeNode*, int> ifRob;
    unordered_map<TreeNode*, int> ifNotRob;
    int rob(TreeNode* root) {
        return handler(root, true);
    }
    int handler(TreeNode* root, bool flag) { // false: cannot rob, true: can rob
        if (!root) return 0;
        int res;
        if (flag == true) { // Rob
            if (ifRob.find(root) != ifRob.end()) {
                return ifRob[root];
            } else {
                int case1 = root->val + handler(root->left, false) + handler(root->right, false);
                int case2 = handler(root->left, true) + handler(root->right, true);
                ifRob[root] = res = max(case1, case2);
            }
        } else { // Not rob
            if (ifNotRob.find(root) != ifNotRob.end()) {
                return ifNotRob[root];
            } else {
                ifNotRob[root] = res = handler(root->left, true) + handler(root->right, true);
            }
        }
        return res;
    }
};
