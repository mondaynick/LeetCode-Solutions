/*
  給定陣列 arr ，求 arr 所有子陣列中其陣列和為奇數的個數，
  如 arr = [1, 3, 5] ，則 arr 的子陣列為 [[1], [3], [5], [1, 3], [1, 5], [3, 5], [1, 3, 5]]，
  其陣列和為 [1, 3, 5, 4, 6, 8, 9] ，只有 [1, 3, 5, 9] 4個子陣列其陣列和為奇數

  利用前綴和，欲求 presum[i] 其子陣列為奇數的個數：
    若 presum[i] 為奇數，則 res 加上 presum[i - 1] 偶數的個數
    若 presum[i] 為偶數，則 res 加上 presum[i - 1] 奇數的個數
 */

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int len = arr.size();
        int presum = 0;
        int res = 0, odd = 0, even = 1;
        for (int i = 0 ; i < len ; i++) {
            presum += arr[i];
            if (presum % 2 == 0) {
                res = (res + odd) % MOD;
                even++;
            } else {
                res = (res + even) % MOD;
                odd++;
            }
        }
        return res;
    }
};
