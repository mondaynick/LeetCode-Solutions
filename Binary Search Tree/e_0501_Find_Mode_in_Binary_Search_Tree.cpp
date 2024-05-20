/*
  給定一棵含重複值的二元搜尋樹，回傳該樹中頻率出現最多次的數字，若有多個元素頻率相同，則回傳多個元素

  利用中序走訪，用hash table紀錄每個元素出現的次數
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
    vector<int> findMode(TreeNode* root) {
        TreeNode* curr = root;
        map<int, int> memo;
        stack<TreeNode*> s;
        int maxFreq = 1;

        while (curr || !s.empty()) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = s.top();
                s.pop();
                if (memo.count(temp->val)) {
                    memo[temp->val]++;
                    if (memo[temp->val] > maxFreq)
                        maxFreq = memo[temp->val];
                } else {
                    memo[temp->val] = 1;
                }
                curr = temp->right;
            }
        }
        
        vector<int> res;
        for (auto m: memo) {
            if (m.second == maxFreq)
                res.push_back(m.first);
        }
        return res;
    }
};
