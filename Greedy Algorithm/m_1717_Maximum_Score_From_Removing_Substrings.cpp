/*
  給定一個字串 s 和兩個整數 x 和 y ，你可以對字串 s 進行以下操作無限次直至無限刪除：
    (1) 刪除子字串 "ab" 獲得分數 x
    (2) 刪除字字串 "ba" 獲得分數 y
  回傳字串 s 進行以上操作可護得的最大分數為何

  利用貪婪演算法，先比對若刪除 "ab" 比刪除 "ba" 獲得的分數較少，則兩者互換，
  先看刪除 "ab" 可以獲得多少分數，再看刪除 "ba" 可以獲得多少分數
 */

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        char char1 = 'a', char2 = 'b';
        if (x < y) {
            swap(x, y);
            swap(char1, char2);
        }
        stack<char> stk1, stk2;
        for (char c : s) {
            if (!stk1.empty() && stk1.top() == char1 && c == char2) {
                stk1.pop();
                res += x;
            } else {
                stk1.push(c);
            }
        }
        while (!stk1.empty()) {
            char c = stk1.top();
            stk1.pop();
            if (!stk2.empty() && stk2.top() == char1 && c == char2) {
                stk2.pop();
                res += y;
            } else {
                stk2.push(c);
            }
        }
        return res;
    }
};
