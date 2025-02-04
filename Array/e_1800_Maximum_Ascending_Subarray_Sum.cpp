/*
  給定一個陣列 nums ，球該陣列的遞增子陣列其和為最大

  遍歷 nums ， record 紀錄目前遍歷的遞增子陣列之和
 */

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int res = nums[0];
        int record = nums[0];
        for (int i = 1 ; i < nums.size() ; i++) {
            if (nums[i] > nums[i - 1]) {
                record += nums[i];
            } else {
                record = nums[i];
            }
            res = max(res, record);
        }
        return res;
    }
};
