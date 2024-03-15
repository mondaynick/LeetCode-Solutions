/*
  給定兩個字串word1和word2，可對一個字串進行三種操作：
    1. 插入一個字元
    2. 刪除一個字元
    3. 替換一個字元
  求將word1轉換至word2最少需要經過幾次操作

  利用動態規劃
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp (len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1 ; i <= len1 ; i++) dp[i][0] = i;
        for (int i = 1 ; i <= len2 ; i++) dp[0][i] = i;
        for (int i = 1 ; i <= len1 ; i++) {
            for (int j = 1 ; j <= len2 ; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[len1][len2];
    }
};
