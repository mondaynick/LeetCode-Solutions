/*
  給定一數獨，回傳其答案

  每次塞進某數字前，檢查其該列、該行、該3x3區塊是否有重複的數字
 */

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        set<char> rows[9], cols[9], sqas[3][3];
        stack<pair<int, int>> pits;

        function<void(void)> init = [&] (void) {
            for (int i = 0 ; i < 9 ; i++) {
                for (int j = 0 ; j < 9 ; j++) {
                    if (board[i][j] == '.') {
                        pits.push({i, j});
                    } else {
                        rows[i].insert(board[i][j]);
                        cols[j].insert(board[i][j]);
                        sqas[i / 3][j / 3].insert(board[i][j]);
                    }
                }
            }
        };

        function<void(int, int, char)> setN = [&] (int r, int c, char n) {
            board[r][c] = n;
            rows[r].insert(n);
            cols[c].insert(n);
            sqas[r / 3][c / 3].insert(n);
            pits.pop();
        };

        function<void(int, int, char)> unSetN = [&] (int r, int c, char n) {
            board[r][c] = '.';
            rows[r].erase(n);
            cols[c].erase(n);
            sqas[r / 3][c / 3].erase(n);
            pits.push({r, c});
        };

        function<bool(void)> dfs = [&] (void) {
            if (pits.empty()) return true;
            int r = pits.top().first, c = pits.top().second;
            for (int i = 0 ; i < 9 ; i++) {
                char n = i + '1';
                if (!rows[r].count(n) && !cols[c].count(n) && !sqas[r / 3][c / 3].count(n)) {
                    setN(r, c, n);
                    if (dfs()) return true;
                    unSetN(r, c, n);
                }
            }
            return false;
        };

        init();
        dfs();
    }
};
