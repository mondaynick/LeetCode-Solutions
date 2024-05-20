/*
  給定一個已排列好的陣列，還原成一棵平衡二元搜尋樹

  每次取中間的值作為根節點，並遞迴左和右子樹分別為陣列中間左邊和右邊的元素
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
    TreeNode* handler(vector<int> nums, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = handler(nums, start, mid - 1);
        res->right = handler(nums, mid + 1, end);
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return handler(nums, 0, nums.size() - 1);
    }
};
