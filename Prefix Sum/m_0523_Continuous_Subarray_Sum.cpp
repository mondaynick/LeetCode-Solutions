/*
  給定一整數陣列 nums 和整數 k ，算出 nums 中一共有幾個和為 k 的倍數的子陣列且其長度至少為 2

  定義 range(i, j) 為 nums[i] ~ nums[j] 的數值加總，因此 range(i, j) = prefixSums[j] - prefixSums[i - 1]
  故 prefixSum[j] - range(i, j) = prefixSum[i - 1]
 */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1) return false;
        unordered_map<int, int> memo;
        memo[0] = -1;
        int prefixSum = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            prefixSum += nums[i];
            int r = prefixSum % k;
            if (memo.count(r)) {
                if (i - memo[r] > 1) return true;
            } else {
                memo[r] = i;
            }
        }
        return false;
    }
};
