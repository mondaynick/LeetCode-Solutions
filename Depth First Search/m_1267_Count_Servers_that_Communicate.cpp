/*
  給定一個mxn的整數陣列，代表了一個伺服器中心的地圖，陣列中每個1代表該處有伺服器，
  0代表該處沒有伺服器，兩個伺服器只有位在相同直航或相同橫列時，被認為互相溝通，回傳
  和其他伺服器溝通的伺服器總數

  利用dfs
 */

class Solution {
public:
    int dfs(vector<vector<int>> &grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 1;
        grid[row][col] = 0;
        for (int i = 0 ; i < cols ; i++) { // traverse its row
            if (grid[row][i] == 1) {
                res += dfs(grid, row, i);
            }
        }
        for (int i = 0 ; i < rows ; i++) { // traverse its column
            if (grid[i][col] == 1) {
                res += dfs(grid, i, col);
            }
        }
        return res;
    }
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0 ; i < grid.size() ; i++) {
            for (int j = 0 ; j < grid[0].size() ; j++) {
                if (grid[i][j] == 1) {
                    int temp = dfs(grid, i, j);
                    if (temp > 1) res += temp;
                }
            }
        }
        return res;
    }
};
