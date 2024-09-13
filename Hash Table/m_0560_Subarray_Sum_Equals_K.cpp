/*
  給定一整數陣列nums和整數k，算出nums中一共有幾個和為k的子陣列

  首先，算出prefixSum，舉例如下：
  nums         3  5  2 -2  4  1
  prefixSum 0  3  8 10  8 12 13
  利用nested for loop
  ans = 0
  for i in range(1, n)
    for j in range(0, i)
      if (prefixSum[i] - prefixSum[j] == k)
        ans++
  但因為nested for loop complexity太高了，我們可以改善它
  先將 prefixSum[i] - prefixSum[j] == k 換作 prefixSum[j] == prefixSum[i] - k
  每次遍歷陣列時做以下事情：
  (1) 紀錄prefixSum，以下記錄到sum_i
  (2) 查詢hash table中滿足sum_j有幾個
  (3) 將sum_i加入hash table
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> memo;
        memo[0] = 1;
        int res = 0, sum_i = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            sum_i += nums[i];
            int sum_j = sum_i - k;
            if (memo.count(sum_j)) {
                res += memo[sum_j];
            }
            if (memo.count(sum_i)) {
                memo[sum_i]++;
            } else {
                memo[sum_i] = 1;
            }
        }
        return res;
    }
};
