/*
  給定x和n，回傳x ^ n

  冪次運算利用二進位會比直接相乘來得快，若n為負數回傳1 / 答案，反之則回傳答案
 */

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1, base = x;
        bool flag = (n >= 0);
        while (n) {
            if (n & 1) ans *= base;
            base *= base;
            n /= 2;
        }
        return flag ? ans : 1 / ans;
    }
};
