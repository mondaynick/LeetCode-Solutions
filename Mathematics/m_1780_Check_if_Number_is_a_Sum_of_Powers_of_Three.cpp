/*
  給定一個整數 n ，回傳 n 檢是否為數個不同的 3 的次方數所加總

  如果這個數字是 3 的倍數加上 2 ，那麼他一定無法被若干個不同的三的冪組合，因為最後的 2 不能再拆分成 1 + 1 了
 */

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n != 0) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};
