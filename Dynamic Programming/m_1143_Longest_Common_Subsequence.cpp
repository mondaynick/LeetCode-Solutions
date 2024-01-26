/*
  給定兩字串，求兩字串的最大共同子字串(不一定要相連)

  當兩字元相同時，dp[i][j] = 1 + dp[i - 1][j - 1]
  當兩字元不同時，dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1len = text1.length(), t2len = text2.length();
        vector<vector<int>> dp (t1len+1, vector<int>(t2len+1, 0));
        for (int i = 1 ; i <= t1len ; i++) {
            for (int j = 1 ; j <= t2len ; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1+ dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[t1len][t2len];
    }
};
