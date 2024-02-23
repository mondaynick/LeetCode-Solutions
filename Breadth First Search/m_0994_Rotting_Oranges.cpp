/*
  給定一個二維陣列，可以視為一個裝橘子的箱子，grid為橘子在箱子第0天所有位置的狀況，如下解釋：
    0：該位置沒有任何東西
    1：該位置的橘子是新鮮的
    2：該位置的橘子是腐壞的
  若第k天這個橘子是腐壞的，則第k+1天該橘子四周(即上下左右)若存在新鮮的橘子則該橘子會腐壞，
  回傳需要花多少天可以讓箱子內所有橘子腐爛，若答案為無解則回傳-1

  定義一個lt，每次儲存第k天新鮮的橘子有哪些，遍歷這些橘子，在第k+1天時，
  若該橘子會變成不新鮮，則將該橘子存到new_rotten，否則存到new_lt，
  遍歷完成後，若lt的數量等於new_lt代表情況已定，跳出迴圈，
  若lt還有東西則代表情況無解，否則回傳共花了多少天
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int res = 0;
        vector<pair<int, int>> lt;
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ; j++) {
                if (grid[i][j] == 1) lt.push_back({i, j});
            }
        }

        function <bool(int, int)> checkRotten = [&] (int i, int j) {
            if (i - 1 >= 0 && grid[i - 1][j] == 2) return true;
            if (i + 1 < row && grid[i + 1][j] == 2) return true;
            if (j - 1 >= 0 && grid[i][j - 1] == 2) return true;
            if (j + 1 < col && grid[i][j + 1] == 2) return true;
            return false;
        };

        while (true) {
            vector<pair<int, int>> new_lt;
            vector<pair<int, int>> new_rotten;
            for (auto l: lt) {
                if (checkRotten(l.first, l.second))
                    new_rotten.push_back({l.first, l.second});
                else
                    new_lt.push_back({l.first, l.second});
            }
            if (new_lt.size() == lt.size()) {
                break;
            } else {
                res++;
                lt = new_lt;
                for (auto l: new_rotten) {
                    grid[l.first][l.second] = 2;
                }
            }
        }
        return lt.empty() ? res : -1;
    }
};
