/*
  給定一個 m x n 的矩陣 mat ，回傳一個 m x n 的矩陣其中每個非零元素代表其在 mat 矩陣與任一零元素的最小距離為何

  利用breadth first search
 */

class Solution {
public:
    void fill(vector<vector<int>>& board, int row, int col, queue<pair<int, int>>& q) {
        int rowlen = board.size(), collen = board[0].size();
        if (row - 1 >= 0 && board[row - 1][col] == -1) {
            q.push({row - 1, col});
            board[row - 1][col] = board[row][col] + 1;
        }
        if (col - 1 >= 0 && board[row][col - 1] == -1) {
            q.push({row, col - 1});
            board[row][col - 1] = board[row][col] + 1;
        }
        if (row + 1 < rowlen && board[row + 1][col] == -1) {
            q.push({row + 1, col});
            board[row + 1][col] = board[row][col] + 1;
        }
        if (col + 1 < collen && board[row][col + 1] == -1) {
            q.push({row, col + 1});
            board[row][col + 1] = board[row][col] + 1;
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowlen = mat.size(), collen = mat[0].size();
        vector<vector<int>> res(rowlen, vector<int>(collen, -1));
        queue<pair<int, int>> q;
        for (int i = 0 ; i < rowlen ; i++) {
            for (int j = 0 ; j < collen ; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            fill(res, temp.first, temp.second, q);
        }
        return res;
    }
};
