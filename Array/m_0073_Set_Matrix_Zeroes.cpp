/*
  給定一個二維陣列 matrix ，若 matrix[i][j] 為 0 ，則將其第 i 列和第 j 行的所有值設成 0

  先記錄哪些列、哪些行有出現 0 ，再將出現 0 的行、列其所有值設成 0
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowlen = matrix.size();
        int collen = matrix[0].size();
        vector<bool> isRowZero(rowlen, false);
        vector<bool> isColZero(collen, false);
        for (int row = 0 ; row < rowlen ; ++row) {
            for (int col = 0 ; col < collen ; ++col) {
                if (matrix[row][col] == 0) {
                    isRowZero[row] = true;
                    isColZero[col] = true;
                }
            }
        }
        for (int row = 0 ; row < rowlen ; ++row) {
            if (isRowZero[row]) {
                for (int col = 0 ; col < collen ; ++col) {
                    matrix[row][col] = 0;
                }
            }
        }
        for (int col = 0 ; col < collen ; ++col) {
            if (isColZero[col]) {
                for (int row = 0 ; row < rowlen ; ++row) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};
