/*
  你有n個硬幣，且你想要用這些硬幣來排出一個階梯的形狀，這個階梯有k個橫列，第i個橫列
  剛好會有i個硬幣，最下面的那個橫列可以不用填滿，回傳該階梯完整的橫列數

  k(k + 1)         (k + 1)[(k + 1) + 1]
  --------  <= n < --------------------
     2                      2
      sqrt(1 + 8n) - 1
  k = ----------------
             2
 */

class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1 + 8 * (long)n) - 1) / 2;
    }
};
