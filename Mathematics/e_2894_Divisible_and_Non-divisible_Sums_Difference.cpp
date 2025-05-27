/*
  給定一個整數 n 和整數 m ，定義以下：
    num1 為 [1, n] 中所有不被 m 整除之和
    num2 為 [1, n] 中所有被 m 整除之和
  回傳 num1 - num2

  根據定義，遍歷 1 到 n 之間的數字
 */

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for (int i = 1 ; i <= n ; ++i) {
            if (i % m == 0) {
                num2 += i;
            } else {
                num1 += i;
            }
        }
        return num1 - num2;
    }
};
