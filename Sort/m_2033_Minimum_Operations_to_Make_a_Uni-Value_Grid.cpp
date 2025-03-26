/*
  給定一格二維矩陣 grid 和整數 x ，而 grid[i][j] 中的每個數字每次都可以增加 x 或減少 x ，
  求將 grid 中每個數字變成相同所需的最小次數，若無法變成相同則回傳 -1

  先判斷是否可以變成相同的數字，再判斷變成相同數字所需的次數
 */

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rows = grid.size(), cols = grid[0].size();
        int mod = grid[0][0] % x;
        vector<int> nums(rows * cols);
        for (int row = 0 ; row < rows ; ++row) {
            for (int col = 0 ; col < cols ; ++col) {
                int temp = grid[row][col] % x;
                if (temp != mod) return -1;
                nums[cols * row + col] = grid[row][col];
            }
        }
        sort(nums.begin(), nums.end());
        int mid = nums[(rows * cols) / 2];
        int count = 0;
        for (int i = 0 ; i < rows * cols ; ++i) {
            count += abs(nums[i] - mid) / x;
        }
        return count;
    }
};
