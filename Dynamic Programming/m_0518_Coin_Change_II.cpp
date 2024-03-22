/*
  給定不同面額的硬幣coins和總金額amount，回傳利用這些面額之硬幣湊成總金額的硬幣組合數，
  假設每一種面額之硬幣有無限多個

  定義dp[i][j]如下：若只使用coins前i個硬幣的面值，想湊出金額j，則有多少種湊法
  base case定義如下：
    dp[0][...] = 0，因為若不使用任何硬幣面值，則無法湊出任何金額
    dp[...][0] = 1，要湊出目標金額0，不放就是唯一的解
  以下演算法與背包問題雷同
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp (coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0 ; i <= coins.size() ; i++) dp[i][0] = 1;

        for (int i = 1 ; i <= coins.size() ; i++) {
            for (int j = 1 ; j <= amount ; j++) {
                if (coins[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[coins.size()][amount];
    }
};
