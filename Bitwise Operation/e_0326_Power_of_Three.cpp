/*
  給定一數數，回傳該整數是否為2的n次方

  若k為3的n次方，則log3(n)必為整數，利用換底公式
  log3(n) = log10(n) / log10(3)確認是否為整數
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double temp = log10(n) / log10(3);
        return (temp - (int)temp) == 0;
    }
};
