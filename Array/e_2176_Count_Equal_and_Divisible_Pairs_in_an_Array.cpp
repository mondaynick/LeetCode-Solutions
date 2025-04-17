/*
  給定一個陣列 nums 和整數 k ，求符合以下條件的個數，其中 0 <= i < j <= nums.size ：
    (1) nums[i] == nums[j]
    (2) (i * j) % k == 0

  利用巢氏迴圈
 */

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int res = 0, len = nums.size();
        for (int i = 0 ; i < len ; ++i) {
            for (int j = i + 1 ; j < len ; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    ++res;
            }
        }
        return res;
    }
};
