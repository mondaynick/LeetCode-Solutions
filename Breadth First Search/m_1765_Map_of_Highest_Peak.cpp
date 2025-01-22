/*
  給定一個 m x n 的矩陣 isWater ，若 isWater[i][j] 為0代表該地方為水，反之為1則該地方為陸地，
  假設水個高度為0，且任兩個相鄰地方的高度絕對值不能超過1，回傳陸地的最高值為何

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

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rowlen = isWater.size(), collen = isWater[0].size();
        vector<vector<int>> res(rowlen, vector<int>(collen, -1));
        queue<pair<int, int>> q;
        for (int i = 0 ; i < rowlen ; i++) {
            for (int j = 0 ; j < collen ; j++) {
                if (isWater[i][j] == 1) { // is water
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
