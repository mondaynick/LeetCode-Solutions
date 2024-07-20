/*
  給定n天的股價，求透過無線多次的交易可得的最大利潤

  利用greedy，每當股價往上升時，更改最大值，再每一次往下掉前賣出即可得最大利潤
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = prices[0];
        int maxPrice = prices[0];
        int n = prices.size();

        for (int i = 1 ; i < n ;) {
            while (i < n && prices[i] >= prices[i - 1]) { // increasing
                maxPrice = prices[i];
                i++;
            }
            res += maxPrice - minPrice;
            while (i < n && prices[i] <= prices[i - 1]) { // decreasing
                minPrice = prices[i];
                i++;
            }
        }
        return res;
    }
};
