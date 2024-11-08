/*
  給定一二維陣列，回傳其島嶼中最大的節點個數

  利用bfs
 */

class Solution {
public:
    void bfs(int &maxVal, vector<vector<int>> &grid, int row, int col) {
        grid[row][col] = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int currVal = 0;
        queue<pair<int, int>> Q;
        Q.push({row, col});
        while (!Q.empty()) {
            pair<int, int> curr = Q.front();
            Q.pop();
            currVal++;
            if (currVal > maxVal) maxVal = currVal;
            if (curr.first - 1 >= 0 && grid[curr.first - 1][curr.second] == 1) {
                Q.push({curr.first - 1, curr.second});
                grid[curr.first - 1][curr.second] = 0;
            }
            if (curr.first + 1 < rows && grid[curr.first + 1][curr.second] == 1) {
                Q.push({curr.first + 1, curr.second});
                grid[curr.first + 1][curr.second] = 0;
            }
            if (curr.second - 1 >= 0 && grid[curr.first][curr.second - 1] == 1) {
                Q.push({curr.first, curr.second - 1});
                grid[curr.first][curr.second - 1] = 0;
            }
            if (curr.second + 1 < cols && grid[curr.first][curr.second + 1] == 1) {
                Q.push({curr.first, curr.second + 1});
                grid[curr.first][curr.second + 1] = 0;
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxVal = 0;
        for (int i = 0 ; i < grid.size() ; i++) {
            for (int j = 0 ; j < grid[0].size() ; j++) {
                if (grid[i][j] == 0) continue;
                bfs(maxVal, grid, i, j);
            }
        }
        return maxVal;
    }
};
