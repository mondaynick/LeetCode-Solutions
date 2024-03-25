/*
  給定一陣列，若該陣列長度為n + 1，則陣列中的數字只會出現1到n(有可能為不出現、出現一次、出現兩次)，回傳該陣列中重複的數字為何

  若nums[abs(nums[i]) - 1] < 0，則新增到res，
  否則將nums[abs(nums[i]) - 1]的元素變為負
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
