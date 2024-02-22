/*
  給定一二元樹，求最小深度

  利用breadth first search，每次往下找時除了傳入節點還要加上位於哪一層
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> temp;
        q.push({root, 1});
        while (!q.empty()) {
            temp = q.front(); q.pop();
            if (!temp.first->left && !temp.first->right) break;
            if (temp.first->left)  q.push({temp.first->left, temp.second + 1});
            if (temp.first->right) q.push({temp.first->right, temp.second + 1});
        }
        return temp.second;
    }
};
