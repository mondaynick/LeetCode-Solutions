/*
  給定一個整數 n ，回傳一個陣列 { a, b } 滿足以下兩個條件：
    (1) a + b = n
    (2) a 和 b 接不存在任何位數為 0

  依序遍歷所有數字，檢查是否存在位數為 0
 */

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int i;
        for (i = 1; i < n; ++i) {
            if (!hasZero(i) && !hasZero(n - i))
                break;
        }
        return {i, n - i};
    }

private:
    bool hasZero(int num) {
        while (num) {
            if (num % 10 == 0) return true;
            num /= 10;
        }
        return false;
    }
};
