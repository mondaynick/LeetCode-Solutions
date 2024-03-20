/*
  給定一個字串，回傳最長回文子序列的長度

  令dp[i][j]代表s[i]到s[j]之最長回文子序列的長度
  因為i == j代表字串只有一個字，所以dp[i][j] = 1
  因為i > j不存在，所以dp[i][j] = 0
  接著考慮i < j：
    若s[i] == s[j]，則dp[i][j] = dp[i + 1][j - 1] + 2
    否則，dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0 ; i < len ; i++) dp[i][i] = 1;

        for (int i = 1 ; i < len ; i++) {
            for (int j = 0, k = i ; k < len ; j++, k++) {
                if (s[j] == s[k]) {
                    dp[j][k] = dp[j + 1][k - 1] + 2;
                } else {
                    dp[j][k] = max(dp[j + 1][k], dp[j][k - 1]);
                }
            }
        }

        return dp[0][len - 1];
    }
};
