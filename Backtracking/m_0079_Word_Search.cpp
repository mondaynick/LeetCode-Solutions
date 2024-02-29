/*
  給定一二維陣列，判斷該單字是否存在其中，注意走過的格子不可以再走，且每次只能往上下左右其一

  利用backtracking
 */

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int idx, int row, int col) {
        if (idx == word.length()) return true;
        if (board[row][col] != word[idx]) return false;
        char temp = board[row][col];
        
        board[row][col] = '*';
        if (idx + 1 == word.length()) return true;
        if (row - 1 >= 0 && dfs(board, word, idx + 1, row - 1, col))
            return true;
        if (row + 1 < board.size() && dfs(board, word, idx + 1, row + 1, col))
            return true;
        if (col - 1 >= 0 && dfs(board, word, idx + 1, row, col - 1))
            return true;
        if (col + 1 < board[0].size() && dfs(board, word, idx + 1, row, col + 1))
            return true;
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[0].size() ; j++) {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
