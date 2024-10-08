/*
  給定一m * n二維陣列，求一個simple path使得其上元素之和為最小

  當前節點加上從上面來及從左邊來最小者
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp (rows, vector<int>(cols, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1 ; i < rows ; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int i = 1 ; i < cols ; i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1 ; i < rows ; i++) {
            for (int j = 1 ; j < cols ; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[rows - 1][cols - 1];
    }
};
