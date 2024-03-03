/*
  給定一二維陣列，回傳每一層的節點並交互顯示

  利用bfs
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue <TreeNode*> Q;
        Q.push(root);
        bool mode = true;

        while (!Q.empty()) {
            int currSize = Q.size();
            vector<int> temp (currSize, 0);
            for (int i = currSize ; i > 0 ; i--) {
                TreeNode* top = Q.front(); Q.pop();
                if (mode) temp[currSize - i] = top->val;
                else      temp[i - 1] = top->val;
                if (top->left) Q.push(top->left);
                if (top->right) Q.push(top->right);
            }
            mode = !mode;
            res.push_back(temp);
        }

        return res;
    }
};
