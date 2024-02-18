/*
  給定一二維陣列，其中每一列和每一行均已由小排到大，回傳該二維陣列是否存在target

  利用prune and search觀念，若該陣列存在target，則二維陣列左上角的值必小於等於target，右下角的值必大於target
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        while (row <= matrix.size() - 1 && col >= 0) {
            if (matrix[row][col] < target) {
                row++;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                return true;
            }
        }
        return false;
    }
};
