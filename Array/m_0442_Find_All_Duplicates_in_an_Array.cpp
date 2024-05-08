/*
  給定一陣列，若該陣列長度為n，且陣列中的數字只會出現1到n(有可能為不出現、出現一次、出現兩次)，回傳該陣列中重複的數字為何

  若nums[abs(nums[i]) - 1] < 0，則新增到res，否則將nums[abs(nums[i]) - 1]的元素變為負
  減1是為了控制範圍在0～(n - 1)之間來避免存取到陣列外的資料
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                res.push_back(abs(nums[i]));
            } else {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        return res;
    }
};
