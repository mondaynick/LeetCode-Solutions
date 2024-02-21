/*
  給定一陣列，若該陣列長度為n，輸出該陣列中不存在0~n之間哪一個數字

  利用xor-sum的特性，a ^ a = 0
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int res = 0;
        for (int i = 0 ; i < length ; i++) {
            res ^= (i ^ nums[i]);
        }
        return res ^ length;
    }
};
