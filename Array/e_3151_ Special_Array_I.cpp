/*
  若一個陣列任兩個相鄰的元素皆為一個為奇數、一個為偶數則該陣列為 special ，
  給定一個陣列 nums ，回傳 nums 是否為 special

  奇數 + 奇數 = 偶數
  偶數 + 偶數 = 偶數
  奇數 + 偶數 = 奇數
 */

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) return true;
        for (int i = 0 ; i < nums.size() - 1 ; i++) {
            if ((nums[i] + nums[i + 1]) % 2 == 0) return false;
        }
        return true;
    }
};
