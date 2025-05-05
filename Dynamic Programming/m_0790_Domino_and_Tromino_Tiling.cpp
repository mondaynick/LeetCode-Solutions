/*
  給定一整數 n ，回傳利用若干塊 1 * 2 的骨牌和 L 形骨牌填補 1 * n 的總方法數

  根據定義不難發現，An = An-1 + An-2 + 2 * (An-3 + ... + A0) ，
  其中初始條件 A0 = 1, A1 = 1, A2 = 2 ，
  利用動態規劃求得
 */

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        long long mod = 1e9 + 7;
        long long preSum = 0;
        for (int i = 3 ; i <= n ; ++i) {
            preSum += dp[i - 3] % mod;
            dp[i] += dp[i - 1] % mod;
            dp[i] += dp[i - 2] % mod;
            dp[i] += (2 * preSum) % mod;
        }
        return dp.back() % mod;
    }
};
