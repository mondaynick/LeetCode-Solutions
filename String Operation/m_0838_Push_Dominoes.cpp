/*
  有 n 個骨牌，骨牌間彼此排成一列，給定 dominoes ，其中 dominoes[i] 代表以下動作：
    dominoes[i] == '.' ：該骨牌不動
    dominoes[i] == 'L' ：將該骨牌往左推
    dominoes[i] == 'R' ：將該骨牌往右推
  假設所有骨牌同時施力，若一個骨牌已經往一邊倒則不會再往另一邊倒，當不同方向的骨牌相遇時會產生
  淨力平衡，求骨牌的最終穩定狀態

  利用兩次遍歷 dominoes 來計算左推力和右推力，最後將兩推力的總和計算出淨推力，若：
    淨推力 = 0 ：該骨牌最終保持站立狀態
    淨推力 < 0 ：該骨牌最終會向左邊倒
    淨推力 > 0 ：該骨牌最終會向右邊倒
 */

class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.length();
        vector<int> force(len, 0);
        int c = 0;
        // from left to right
        for (int i = 0 ; i < len ; ++i) {
            if (c > 0 && dominoes[i] == '.') {
                c--;
            } else if (dominoes[i] == 'L') {
                c = 0;
            } else if (dominoes[i] == 'R') {
                c = len;
            }
            force[i] = c;
        }
        // from right to left
        c = 0;
        for (int i = len - 1 ; i >= 0 ; --i) {
            if (c > 0 && dominoes[i] == '.') {
                c--;
            } else if (dominoes[i] == 'L') {
                c = len;
            } else if (dominoes[i] == 'R') {
                c = 0;
            }
            force[i] -= c;
        }
        string res(len, '.');
        for (int i = 0 ; i < len ; ++i) {
            if (force[i] < 0) {
                res[i] = 'L';
            } else if (force[i] > 0) {
                res[i] = 'R';
            }
        }
        return res;
    }
};
