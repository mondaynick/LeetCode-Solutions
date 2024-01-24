/*
  給定所有住家的價值且住家在一條街道上，若一個晚上有連續兩間被偷會觸發警報，輸出再不觸發警報的情況下最多可以偷多少

  若偷這間，則前一間不偷，若不偷這間，則前一間可以偷，
  若偷第1間則看第1間到第n - 1間的價值，若不偷第1間則看第2間到第n間的價值，取其大者
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int l = nums.size();
        // Not rob the first one.
        int prev = 0, curr = nums[1];
        for (int i = 2 ; i < l ; i++) {
            int temp = prev;
            prev = curr;
            curr = max(nums[i]+temp, prev);
        }
        int res = curr;
        // Rob the first one.
        prev = nums[0], curr = max(nums[0], nums[1]);
        for (int i = 2 ; i < l - 1 ; i++) {
            int temp = prev;
            prev = curr;
            curr = max(nums[i]+temp, prev);
        }
        return max(res, curr);
    }
};
