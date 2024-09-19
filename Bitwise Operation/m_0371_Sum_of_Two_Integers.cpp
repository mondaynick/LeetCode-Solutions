/*
  給定兩個整數，將其相加但不能使用+和-

    0 0 0 1    0 0 0 1
  + 0 1 0 1  ^ 0 1 0 1
  = 0 1 1 0  = 0 1 0 0
  由上面我們可以發現xor只有在進位時不一樣，而計算進位使用and，因為只有兩者為1時才會進位
  遞迴直到進位為0
 */

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return getSum(a ^ b, (a & b) << 1);
        }
    }
};
