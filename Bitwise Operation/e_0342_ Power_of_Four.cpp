/*
  給定一數數，回傳該整數是否為4的n次方

  若一個整數為4的n次方，則該數必為2的次方而，該整數只有一個位元為1而且該位置必為奇數的位置
 */

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0x55555555) == n);
    }
};
