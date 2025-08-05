/*
  給定兩個長度為 n 的陣列 fruits 和 baskets ，其中 fruits[i] 代表第 i 種水果的重量，且 basket[i] 代表第 i 個籃子可以承受的重量，
  水果需要根據以下規則放置於籃子：
    (1) 一個籃子只能放置一種水果
    (2) 該種水果的重量必須小於或等於該籃子的重量，才可以放進去該籃子
    (3) 水果必須從最左邊(索引從最小開始)的籃子開始放

  利用巢狀迴圈
 */

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = fruits.size();
        vector<bool> isPlaced(res, false);
        for (int fruit : fruits) {
            for (int i = 0; i < isPlaced.size(); ++i) {
                if (!isPlaced[i] && baskets[i] >= fruit) {
                    isPlaced[i] = true;
                    --res;
                    break;
                }
            }
        }
        return res;
    }
};
