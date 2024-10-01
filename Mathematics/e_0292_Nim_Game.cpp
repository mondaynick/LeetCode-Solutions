/*
  兩個人面前有一堆石頭，每個人輪流拿，一人至少1顆、至多3顆，從你開始拿，
  若拿到最後石頭的人勝利，給定n顆石頭回傳你是否取勝

  若石頭為4的倍數時必輸
 */

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
