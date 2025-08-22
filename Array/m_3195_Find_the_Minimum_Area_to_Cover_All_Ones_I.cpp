/*
  給定一個二維陣列 grid ，找到一個最小面積的矩形其包含 grid 所有的 1

  紀錄上、下、左、右邊界
 */

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rowmin = INT_MAX, rowmax = -1;
        int colmin = INT_MAX, colmax = -1;
        int rowlen = grid.size();
        int collen = grid[0].size();

        for (int row = 0; row < rowlen; ++row) {
            for (int col = 0; col < collen; ++col) {
                if (grid[row][col] == 1) {
                    rowmin = min(rowmin, row);
                    rowmax = max(rowmax, row);
                    colmin = min(colmin, col);
                    colmax = max(colmax, col);
                }
            }
        }

        return (rowmax - rowmin + 1) * (colmax - colmin + 1);
    }
};
