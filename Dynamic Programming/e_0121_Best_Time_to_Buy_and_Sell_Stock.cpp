/*
  給定n天的股價，求其最大可賺的價差

  利用兩個變數，一個紀錄當前最小值，一個紀錄當前最大利潤
 */

class Solution {
public:
    int maxProfit(vector<int> prices) {
        int profit = 0
        int minima = prices[0]
        for (int i = 1 ; i < len(prices) ; i++) {
            minima = min(minima, prices[i])
            profit = max(profit, prices[i] - minima)
            return profit
        }
    }
};
