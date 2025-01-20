/*
  給定一個陣列arr和一個大小為m×n的陣列mat，arr和mat兩者都包含位於範圍[1,m×n]中的所有整數
  掃過arr中每一個索引值i（從索引值 0 開始）來把arr[i]位於mat中的那一格格子塗上顏色
  回傳最小的索引值i使得mat中某一列或某一行是全部都有塗上顏色的

  利用hash table
 */

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rowlen = mat.size(), collen = mat[0].size();
        unordered_map<int, pair<int, int>> memo;
        for (int i = 0 ; i < rowlen ; i++) {
            for (int j = 0 ; j < collen ; j++) {
                memo[mat[i][j]] = {i, j};
            }
        }
        vector<int> atRow(rowlen, 0), atCol(collen, 0);
        int res = -1;
        for (int ite: arr) {
            res++;
            pair<int, int> pos = memo[ite];
            atRow[pos.first]++;
            atCol[pos.second]++;
            if (atRow[pos.first] == collen || atCol[pos.second] == rowlen) break;
        }
        return res;
    }
};
