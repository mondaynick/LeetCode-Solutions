/*
  給定一樹根，求levelorder traversal

  利用queue並傳入位於樹的第幾層
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> currData = q.front(); q.pop();
            TreeNode* currNode = currData.first;
            int currLevel = currData.second;

            if (currLevel + 1 > res.size()) {
                res.push_back(vector<int>(1, currNode->val));
            } else {
                res[currLevel].push_back(currNode->val);
            }
            if (currNode->left) q.push({currNode->left, currLevel + 1});
            if (currNode->right) q.push({currNode->right, currLevel + 1});
        }
        return res;
    }
};
