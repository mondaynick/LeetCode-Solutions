/*
  給定n * n的棋盤，求擺放n個皇后且互相無法攻擊到的所有方法數

  利用backtracking
 */

class Solution {
public:
    bool check(vector<int> state, int r) {
        for (int i = 0 ; i < r ; i++)
            if (state[r] == state[i] || (abs(state[r] - state[i]) == r - i))
                return false;
        return true;
    }

    void dfs(vector<int> state, int r, int& res, int n) {
        if (r == n) {
            res++;
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

    int totalNQueens(int n) {
        int res = 0;
        vector<int> state (n, -1);
        int r = 0;

        dfs(state, r, res, n);
        return res;
    }
};
