/*
  給定一陣列，輸入唯一不重複的數值

  因為 a ^ 0 = 0 ^ a = a 又 a ^ a = 0 ，故將其所有元素xor起來即可得到結果
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int res = nums[0];
        for (int i = 1 ; i < nums.size() ; i++) {
            res = res ^ nums[i];
        }
        return res;
    }
};
