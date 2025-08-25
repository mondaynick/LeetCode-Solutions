/*
  給定一個二維陣列 mat ，回傳一維陣列其對二維陣列 mat 做對角線尋訪，遍歷規則詳見 LeetCode

  遍歷二維陣列 mat 時，我們可以根據其當下所在的 row 和 column 索引去判斷當前要往右上還是左下移動:
    如果 row 索引加上 column 索引為奇數，代表該往左下移動，可以分為以下 3 種情況:
      (1) 如果不能往左下移動，也不能往下移動，則往右移動
      (2) 如果不能往左下移動，但可以往下移動，則往下移動
      (3) 如果可以往左下移動，則往左下移動
    如果 row 索引加上 column 索引為偶數，代表該往右上移動，可以分為以下 3 種情況:
      (1) 如果不能往右下移動，也不能往右移動，則往下移動
      (2) 如果不能往右下移動，但可以往右移動，則往右移動
      (3) 如果可以往右下移動，則往右下移動
 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = 0, col = 0;
        int rows = mat.size(), cols = mat[0].size();
        vector<int> res(rows * cols);

        for (int i = 0; i < rows * cols; ++i) {
            res[i] = mat[row][col];

            if ((row + col) & 1) { // go left and down
                if (row == rows - 1) { // if cannot go down then go right
                    ++col;
                } else if (col == 0) { // go down
                    ++row;
                } else { // go left and down
                    ++row;
                    --col;
                }
            } else { // go right and top
                if (col == cols - 1) { // if cannot go right then go down
                    ++row;
                } else if (row == 0) { // go right
                    ++col;
                } else { // go right and top
                    --row;
                    ++col;
                }
            }
        }

        return res;
    }
};
