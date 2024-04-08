/*
   給定一數獨，判定是否合法

   利用hash table
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> rows[9], cols[9], sqas[3][3];
        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < 9 ; j++) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    int temp = board[i][j];
                    if (rows[i].count(temp) || cols[j].count(temp) || sqas[i / 3][j / 3].count(temp))
                        return false;
                    rows[i].insert(temp);
                    cols[j].insert(temp);
                    sqas[i / 3][j / 3].insert(temp);
                }
            }
        }
        return true;
    }
};
