/*
  給定一個陣列 nums ，回傳一個其長度和陣列 nums 的陣列 arr 滿足：
    arr[i] = nums[nums[i]], 0 <= i < nums.size

  根據定義
 */

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        for (int i = 0 ; i < len ; ++i) {
            res[i] = nums[nums[i]];
        }
        return res;
    }
};
