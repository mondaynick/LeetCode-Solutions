/*
  給定一陣列，輸入唯一不重複的數值

  因為 a ^ 0 = 0 ^ a = a 又 a ^ a = 0 ，故將其所有元素xor起來即可得到結果
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 1 ; i < nums.size() ; i++)
            nums[i] ^= nums[i - 1];
        return nums[nums.size() - 1];
    }
};
