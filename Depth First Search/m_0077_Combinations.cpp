/*
  給定一陣列，回傳陣列所有數字的組合可能(因為是組合，所以[1, 2]和[2, 1]是相同的)

  利用dfs
 */

class Solution {
public:
    void dfs(int n, int k, int level, vector<int> temp, vector<vector<int>>& res) {
        if (temp.size() == k) {
            res.push_back(temp);
        } else {
            for (int i = level ; i <= n ; i++) {
                temp.push_back(i);
                dfs(n, k, i + 1, temp, res);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(n, k, 1, temp, res);
        return res;
    }
};
