/*
  給定一個陣列 nums ，若一個陣列的子陣列其不同的元素數量等於其陣列的不同元素數量
  則該子陣列稱為 complete subarray ，回傳陣列 nums 有多少個 complete subarray

  利用 sliding window
 */

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> numCount(nums.begin(), nums.end());
        unordered_map<int, int> memo;
        int len = nums.size();
        int left = 0, right = 0, res = 0;
        for (; right < len ; ++right) {
            ++memo[nums[right]];
            while (memo.size() == numCount.size()) {
                res += len - right;
                --memo[nums[left]];
                if (memo[nums[left]] == 0) memo.erase(nums[left]);
                ++left;
            }
        }
        return res;
    }
};
