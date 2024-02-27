/*
  假設一開始位於陣列的第一個要往右邊跳，陣列中的每個元素代表當前位置最多可以往右跳幾格，
  若可以從陣列的最左邊跳到最右邊，則回傳true，反之則回傳false

  若i > farest，代表當前節點是到不了則回傳false，否則更新farest往下遍歷，遍歷完則回傳true
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (i > farest) return false;
            farest = max(farest, i + nums[i]);
        }
        return true;
    }
};
