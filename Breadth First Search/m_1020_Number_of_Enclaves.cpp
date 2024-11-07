/*
  給定一二維陣列，回傳共有幾個元素不含邊界元素相鄰

  利用bfs，先將邊界元素相鄰的元素變成0，再計算不是邊界元素中有多少個1
 */

class Solution {
private:
    void bfs(vector<vector<int>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> Q;
        Q.push({row, col});
        while (!Q.empty()) {
            pair<int, int> curr = Q.front();
            Q.pop();
            if (curr.first - 1 >= 0 && grid[curr.first - 1][curr.second] == 1) {
                grid[curr.first - 1][curr.second] = 0;
                Q.push({curr.first - 1, curr.second});
            }
            if (curr.first + 1 < rows && grid[curr.first + 1][curr.second] == 1) {
                grid[curr.first + 1][curr.second] = 0;
                Q.push({curr.first + 1, curr.second});
            }
            if (curr.second - 1 >= 0 && grid[curr.first][curr.second - 1] == 1) {
                grid[curr.first][curr.second - 1] = 0;
                Q.push({curr.first, curr.second - 1});
            }
            if (curr.second + 1 < cols && grid[curr.first][curr.second + 1] == 1) {
                grid[curr.first][curr.second + 1] = 0;
                Q.push({curr.first, curr.second + 1});
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0 ; i < cols ; i++) {
            if (grid[0][i] == 1) bfs(grid, 0, i);
            if (grid[rows - 1][i] == 1) bfs(grid, rows - 1, i);
        }
        for (int i = 1 ; i < rows - 1 ; i++) {
            if (grid[i][0] == 1) bfs(grid, i, 0);
            if (grid[i][cols - 1] == 1) bfs(grid, i, cols - 1);
        }
        int count = 0;
        for (int row = 1 ; row < rows - 1 ; row++) {
            for (int col = 1 ; col < cols - 1 ; col++) {
                if (grid[row][col] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
