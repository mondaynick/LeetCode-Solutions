/*
  給定numRows，回傳前numRows列的帕斯卡三角形

  根據定義
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        for (int i = 2 ; i <= numRows ; i++) { // ith row
            vector<int> currRow = {1};
            vector<int> prevRow = res.back();
            for (int j = 1 ; j < i ; j++) {
                int prev = prevRow[j - 1];
                int curr = (j == i - 1) ? 0 : prevRow[j];
                currRow.push_back(prev + curr);
            }
            res.push_back(currRow);
        }
        return res;
    }
};
