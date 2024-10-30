/*
  有一個無向的星型圖，回傳其中間頂點

  遍歷邊並記錄度數
 */

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> deg;
        for (vector<int> ite: edges) {
            deg[ite[0]]++;
            deg[ite[1]]++;
        }
        int size = deg.size();
        for (pair<int, int> ite: deg) {
            if (ite.second == size - 1) {
                return ite.first;
            }
        }
        return -1;
    }
};
