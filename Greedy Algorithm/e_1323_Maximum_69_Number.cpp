/*
  給定一個整數 num ，你最多只能將一個位數的 6 變成 9 或者是將 9 變成 6 ，回傳最多只能變一位數的情況下
  其變完的數字最大值

  利用貪婪演算法，將最左邊的 6 換成 9 即可
 */

class Solution {
public:
    int maximum69Number (int num) {
        string temp = to_string(num);
        int len = temp.length();
        for (int i = 0; i < len; ++i) {
            if (temp[i] == '6') {
                temp[i] = '9';
                break;
            }
        }
        return stoi(temp);
    }
};
