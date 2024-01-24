/*
  給定一個m * n的棋盤，從左上角開始，每次只能往下一格或往右一格，求走到右下角共有幾種走法，並新增了障礙物

  對於任何一格，走至該格的方法有從上往下或從左到右，方法數為相加，若有障礙物則忽略不計
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (NULL == &obstacleGrid || obstacleGrid[0][0] == 1)
            return 0;
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = 1;
        for (int i = 0 ; i < rows ; i++) {
            for (int j = 0 ; j < cols ; j++) {
                if (obstacleGrid[i][j] != 1) {
                    if (i - 1 >= 0)
                        dp[i][j] += dp[i - 1][j];
                    if (j - 1 >= 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};
