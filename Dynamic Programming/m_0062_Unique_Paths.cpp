/*
  給定一個m * n的棋盤，從左上角開始，每次只能往下一格或往右一格，求走到右下角共有幾種走法

  對於任何一格，走至該格的方法有從上往下或從左到右，方法數為相加
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1 ; i < m ; i++) {
            for (int j = 1 ; j < n ; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
