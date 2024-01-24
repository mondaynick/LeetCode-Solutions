/*
  給定n天的股價，求其最大可賺的價差

  利用兩個變數，一個紀錄當前最小值，一個紀錄當前最大利潤
 */

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        minima = prices[0]
        for i in range(1, len(prices)):
            minima = min(minima, prices[i])
            profit = max(profit, prices[i] - minima)
        return profit
