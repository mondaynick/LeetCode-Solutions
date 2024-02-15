/*
  給定一二維陣列，其升冪排序從左到右、從上到下，輸出是否存在target

  利用二元搜尋法
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int lo = 0, hi = rows * cols - 1, mid;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int row = mid / cols;
            int col = mid % cols;
            if (target == matrix[row][col]) {
                return true;
            } else if (target > matrix[row][col]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
