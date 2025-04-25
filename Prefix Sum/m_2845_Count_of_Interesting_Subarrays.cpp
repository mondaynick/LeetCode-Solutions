/*
  給定一個陣列 nums 、整數 modulo 和整數 k ，若 nums 的子陣列 subnums[i...j] 滿足以下條件，
  則稱 subnums 為 interesting：令 cnt 為 subnums[i] % modulo == k 的數量，其中 j <= i
  <= k ， 則 cnt % modulo == k ，回傳陣列 nums 中有多少個子陣列為 interesting

  利用 prefix sum 算出目前為止有多少個元素除以 modulo 會等於 k，
  再利用 preSum[j] - range(i, j) = preSum[i - 1] 求得答案
 */

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long prefixSum = 0, res = 0;
        unordered_map<int, int> memo;
        memo[0] = 1;
        for (auto num: nums) {
            prefixSum += (num % modulo == k);
            res += memo[(prefixSum - k) % modulo];
            ++memo[prefixSum % modulo];
        }
        return res;
    }
};
