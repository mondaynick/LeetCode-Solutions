/*
  給定一二元樹，求哪一層的所有元素總和為最大值(根為第一層且若多層相同請回傳最小的那一層)

  利用queue加bfs
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
    int maxLevelSum(TreeNode* root) {
        int maxCount, level = 0, maxLevel;
        queue <TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            level++;
            int count = 0;
            for (int i = Q.size() ; i > 0 ; i--) {
                TreeNode* temp = Q.front(); Q.pop();
                count += temp->val;
                if (temp->left)  Q.push(temp->left);
                if (temp->right) Q.push(temp->right);
            }
            if (level == 1) {
                maxCount = count;
                maxLevel = 1;
            } else if (count > maxCount) {
                maxCount = count;
                maxLevel = level;
            }
        }

        return maxLevel;
    }
};
