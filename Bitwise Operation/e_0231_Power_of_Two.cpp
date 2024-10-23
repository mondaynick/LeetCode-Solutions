/*
  給定一數數，回傳該整數是否為2的n次方

  若該數為2的n次方，則該數必大於0且與其-1 and 必為0
  Ex.1  4  0100
        3  0011
        &  0000
  Ex.2  7  0111
        6  0110
        &  0110
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && (n & (n - 1)) == 0);
    }
};
