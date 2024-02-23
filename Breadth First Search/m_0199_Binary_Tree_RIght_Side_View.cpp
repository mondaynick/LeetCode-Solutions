/*
  給定一二元樹，回傳從右邊往左看看到的所有節點之val，依上往下由陣列方式回傳

  每次遍歷每一層中的所有節點，若為當前最後一個遍歷到的，將該節點的val放到res
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = q.size() - 1 ; i >= 0 ; i--) {
                TreeNode* temp = q.front(); q.pop();
                if (i == 0) res.push_back(temp->val);
                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return res;
    }
};
