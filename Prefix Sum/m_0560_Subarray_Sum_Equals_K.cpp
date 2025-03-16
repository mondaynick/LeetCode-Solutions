/*
  給定一整數陣列 nums 和整數 k ，算出 nums 中一共有幾個和為 k 的子陣列

  定義 range(i, j) 為 nums[i] ~ nums[j] 的數值加總，因此 range(i, j) = prefixSums[j] - prefixSums[i - 1]
  故 prefixSum[j] - range(i, j) = prefixSum[i - 1]
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0, res = 0;
        unordered_map<int, int> memo;
        memo[0] = 1;
        for (int num: nums) {
            prefixSum += num;
            if (memo.count(prefixSum - k)) {
                res += memo[prefixSum - k];
            }
            memo[prefixSum]++;
        }
        return res;
    }
};
