/*
  給定一個長度為 n x n 的矩陣 grid ，其中 grid 的數值介於 1 到 n x n 之間，回傳其中重複的元素和缺少的元素

  利用 hash table
 */

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int len = grid.size();
        int dup, miss;
        unordered_set<int> memo;
        for (int i = 0 ; i < len ; i++) {
            for (int j = 0 ; j < len ; j++) {
                int temp = grid[i][j];
                if (memo.count(temp)) {
                    dup = temp;
                } else {
                    memo.insert(temp);
                }
            }
        }
        for (int i = 1 ; i <= len * len ; i++) {
            if (!memo.count(i)) {
                miss = i;
                break;
            }
        }
        return {dup, miss};
    }
};
