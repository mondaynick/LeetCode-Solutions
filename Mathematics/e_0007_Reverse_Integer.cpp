/*
  給定一整數，回傳該整數的相反且符號不變，即123變成321

  迭代並加入溢位偵測
 */

class Solution {
public:
    int reverse(int x) {
        long temp = 0;
        while (x) {
            temp = temp * 10 + x % 10;
            x /= 10;
        }
        return (temp > INT_MAX || temp < INT_MIN) ? 0 : temp;
    }
};
