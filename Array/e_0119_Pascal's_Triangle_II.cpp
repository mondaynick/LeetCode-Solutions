/*
  給定rowIndex，回傳第rowIndex列的帕斯卡三角形

  根據定義
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        for (int i = 2 ; i <= rowIndex + 1 ; i++) { // ith row
            vector<int> currRow = {1};
            vector<int> prevRow = res;
            for (int j = 1 ; j < i ; j++) {
                int prev = prevRow[j - 1];
                int curr = (j == i - 1) ? 0 : prevRow[j];
                currRow.push_back(prev + curr);
            }
            res = currRow;
        }
        return res;
    }
};
