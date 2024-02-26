/*
  給定n * n的棋盤，求擺放n個皇后且互相無法攻擊到的所有方法

  利用backtracking
 */

class Solution {
public:
    bool check(vector<int> state, int r) {
        for (int i = 0 ; i < r ; i++)
            if (state[i] == state[r] || (abs(state[r] - state[i]) == r - i))
                return false;
        return true;
    }

    vector<string> getPath(vector<int> state, int n) {
        vector<string> path;
        for (int i = 0 ; i < n ; i++) {
            string temp;
            for (int j = 0 ; j < state[i] ; j++) temp += ".";
            temp += 'Q';
            for (int j = 0 ; j < (n - state[i] - 1) ; j++) temp += ".";
            path.push_back(temp);
        }
        return path;
    }

    void dfs(vector<int> state, int r, vector<vector<string>>& res, int n) {
        if (r == n) {
            res.push_back(getPath(state, n));
        } else {
            for (int i = 0 ; i < n ; i++) {
                state[r] = i;
                if (check(state, r)) {
                    r++;
                    dfs(state, r, res, n);
                    r--;
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> state (n, -1);
        int r = 0;

        dfs(state, r, res, n);
        return res;
    }
};
