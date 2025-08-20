/*
  給定一個二維陣列 matrix ，回傳有多少個正方形子陣列其所有元素皆為 1

  利用動態規劃，最大正方形的大小由其上側、左側和左上角的正方形大小之最小值加 1 決定
 */

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int res = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == 1) {
                    if (row - 1 >= 0 && col - 1 >= 0) {
                        matrix[row][col] = 1 + min(
                            min(matrix[row - 1][col], matrix[row][col - 1]),
                            matrix[row - 1][col - 1]
                        );
                    }
                    res += matrix[row][col];
                }
            }
        }
        return res;
    }
};
