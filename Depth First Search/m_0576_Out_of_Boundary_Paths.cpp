/*
  給定最大列數、最大行數、最大步數、起始列數、起始行數，求走出邊界且不超過最大步數共有幾種可能，因為數字相當大，輸出要mod 10^9 + 7

  利用DFS和dictionary紀錄以減少算過得不再重複算，進而避免stack overflow
 */

class Solution {
public:
    const int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        map<vector<int>, int> dict;
        function <int(int, int, int)> handler = [&] (int row, int col, int step) {
            if (dict.find({row, col, step}) != dict.end()) {
                return dict[{row, col, step}];
            } else if (step >= 0) {
                int res1 = (row - 1 < 0) ? 1 : handler(row - 1, col, step - 1);
                int res2 = (row + 1 == m) ? 1 : handler(row + 1, col, step - 1);
                int res3 = (col - 1 < 0) ? 1 : handler(row, col - 1, step - 1);
                int res4 = (col + 1 == n) ? 1 : handler(row, col + 1, step - 1);
                return dict[{row, col, step}] = ((res1 + res2) % mod + (res3 + res4) % mod) % mod;
            } else {
                return 0;
            }
        };
        return handler(startRow, startColumn, maxMove - 1);
    }
};
