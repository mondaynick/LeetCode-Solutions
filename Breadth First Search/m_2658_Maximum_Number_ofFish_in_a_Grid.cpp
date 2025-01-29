/*
  給定一個 m x n 的矩陣 grid ，其中 grid[i][j] = 0 代表陸地， grid[i][j] > 0 代表該水面有多少數量的魚，
  一個漁夫可以從該水面捕捉後再補捉相鄰水面的魚直到相鄰都被探索完，回傳漁夫若只能從一個水面下去最多能捕捉多少的魚

  利用breadth first search
 */

class Solution {
public:
    int bfs(vector<vector<int>>& grid, int row, int col) {
        int res = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        int rows = grid.size(), cols = grid[0].size();
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            res += grid[temp.first][temp.second];
            grid[temp.first][temp.second] = 0;
            if (temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] != 0) {
                q.push({temp.first - 1, temp.second});
            }
            if (temp.first + 1 < rows && grid[temp.first + 1][temp.second] != 0) {
                q.push({temp.first + 1, temp.second});
            }
            if (temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] != 0) {
                q.push({temp.first, temp.second - 1});
            }
            if (temp.second + 1 < cols && grid[temp.first][temp.second + 1] != 0) {
                q.push({temp.first, temp.second + 1});
            }
        }
        return res;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0 ; i < rows ; i++) {
            for (int j = 0 ; j < cols ; j++) {
                if (grid[i][j] == 0) continue;
                int temp = bfs(grid, i, j);
                if (temp > res) res = temp;
            }
        }
        return res;
    }
};
