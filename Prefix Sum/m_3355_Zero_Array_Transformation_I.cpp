/*
  給定一個陣列 nums 和二維陣列 queries ，對於每個 queries[i] = [li, ri] ，
  將 nums[li ...ri] 的值減 1 ，最多減至 0 ，回傳遍歷 queries 後，是否可將 nums
  所有的值變成 0 ，若可以則回傳 true ，否則回傳 false

  利用差分陣列，定義一個長度為 nums.size + 1 的陣列 diff ，其初始值全為 0， 對於
  每個 queries[i] = [li, ri] ，將 diff[li] 的值加 1 且 diff[ri + 1] 的值減 1
  ，累加前綴和 preSum ，若 nums[i] 大於 preSum 代表無法使得該陣列為 zero array，
  回傳 false ，否則回傳 true
 */

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1, 0);
        for (const auto &query : queries) {
            ++diff[query[0]];
            --diff[query[1] + 1];
        }
        int preSum = 0;
        for (int i = 0 ; i < nums.size() ; ++i) {
            preSum += diff[i];
            if (nums[i] > preSum) return false;
        }
        return true;
    }
};
