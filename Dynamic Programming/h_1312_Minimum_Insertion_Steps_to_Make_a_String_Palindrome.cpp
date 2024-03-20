/*
  給定一個字串s，允許在字串的任意位置插入任意字元，如果要把s變成回文，則最少需要多少次插入

  令dp[i][j]等於s[i]到s[j]的變成回文之最小插入次數，因為i不會大於j，所以對於所有i > j，dp[i][j] = 0
  若i == j，則字串只有一個字元，必定為回文， 因此dp[i][j] = 0
  若i < j且s[i] == s[j]，代表s[i]到s[j]為回文不需插入，dp[i][j] = dp[i + 1][j - 1]
  若i < j且s[i] != s[j]，這時要看讓s[i + 1][j]還是s[i][j - 1]變成回文的代價為最小，dp[i][j] = min{dp[i + 1][j], dp[i][j - 1]} + 1
 */

class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();
        vector<vector<int>> dp (len, vector<int>(len, 0));

        for (int i = 1 ; i < len ; i++) {
            for (int j = 0, k = i ; k < len ; j++, k++) {
                if (s[j] == s[k]) {
                    dp[j][k] = dp[j + 1][k - 1];
                } else {
                    dp[j][k] = min(dp[j + 1][k], dp[j][k - 1]) + 1;
                }
            }
        }

        return dp[0][len - 1];
    }
};
