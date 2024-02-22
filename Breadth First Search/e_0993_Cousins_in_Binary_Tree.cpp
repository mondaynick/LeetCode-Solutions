/*
  給定一二元樹及兩個數字，回傳此兩個數字在此二元樹是否為cousin關係(i.e. level相同但parent不同)

  每次遍歷同一層的所有節點：
  1. 先檢查目前遍歷到的節點之左右節點是否存在x及y，若是則回傳false (因為相同層級來自相同父母)
  2. 若兩個數字皆有出現則回傳true，若只出現一個則回傳false (因為已確定是不同層級)
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            bool isX = false, isY = false;
            for (int i = q.size() ; i > 0 ; i--) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->val == x) isX = true;
                if (curr->val == y) isY = true;
                if (curr->left && curr->right) {
                    if ((curr->left->val == x && curr->right->val == y) || (curr->left->val == y && curr->right->val == x))
                        return false;
                }
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (isX && isY) return true;
            if (isX || isY) return false;
        }
        return false;
    }
};
