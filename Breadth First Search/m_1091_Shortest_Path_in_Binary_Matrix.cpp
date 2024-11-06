/*
  給定二維陣列，圖中0是可以走的，1是不能走的，回傳從左上角走到右下角最多需要經過幾個節點，若不可達則回傳-1

  首先，先將所有的0換成無限大，以便等等更新距離，再將所有的1換成-1表示不能通過
  利用bfs，從左上角慢慢擴張，每次更新每個節點的距離，直到右下角為止
 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<int> Position;

        if (grid[0][0]) return -1;
        Position.push(0);
        for (int i = 0 ; i < rows ; i++) {
            for (int j = 0 ; j < cols ; j++) {
                if (grid[i][j]) {
                    grid[i][j] = -1;
                } else {
                    grid[i][j] = INT_MAX;
                }
            }
        }
        grid[0][0] = 1;
        int direction_x[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        int direction_y[8] = {0, 0, -1, 1, 1, -1, -1, 1};
        while (!Position.empty()) {
            int current = Position.front();
            Position.pop();
            int x = current / cols;
            int y = current % cols;
            for (int i = 0 ;i < 8 ; i++) {
                int new_x = x + direction_x[i];
                int new_y = y + direction_y[i];
                int distance = grid[x][y];
                if (new_x < 0 || new_y < 0) continue;
                if (new_x >= rows || new_y >= cols) continue;
                if (grid[new_x][new_y] == -1) continue;
                int distance_now = distance + 1;
                if (distance_now < grid[new_x][new_y]) {
                    grid[new_x][new_y] = distance_now;
                    int P = new_x * cols + new_y;
                    Position.push(P);
                }
            }
        }
        if (grid[rows - 1][cols - 1] != INT_MAX) {
            return grid[rows - 1][cols - 1];
        } else {
            return -1;
        }
    }
};
