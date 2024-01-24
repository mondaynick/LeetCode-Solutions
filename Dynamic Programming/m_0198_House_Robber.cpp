/*
  給定所有住家的價值且住家在一條街道上，若一個晚上有連續兩間被偷會觸發警報，輸出再不觸發警報的情況下最多可以偷多少

  若偷這間，則前一間不偷，若不偷這間，則前一間可以偷
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int len = nums.size();
        vector<int> res (len, 0);
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for (int i = 2 ; i < len ; i++) {
            res[i] = max(nums[i] + res[i - 2], res[i - 1]);
        }
        return res[len - 1];
    }
};
