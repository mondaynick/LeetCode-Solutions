/*
  給定兩字串，求至少要刪除幾個字元，每次只能刪除一個字元，才可以讓這兩個字串的內容完全一致

  利用動態規劃，定義dp[i, j]代表word1前i個字元與word2前j個字元若要相等的最小刪除次數
  dp[i][0] = i                                把字串長度為i變成空字串需刪除i個字元
  dp[0][i] = i                                把字串長度為i變成空字串需刪除i個字元
  dp[i][j] = dp[i-1][j-1]                     word1第i個字元與word2第j個字元相同
  dp[i][j] = 1 + min(dp[i-1][j], dp[i[][j-1]) 刪除word1第i個字元或word2第j個字元
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0 ; i <= len1 ; i++) dp[i][0] = i;
        for (int i = 0 ; i <= len2 ; i++) dp[0][i] = i;
        for (int i = 1 ; i <= len1 ; i++) {
            for (int j = 1 ; j <= len2 ; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};
