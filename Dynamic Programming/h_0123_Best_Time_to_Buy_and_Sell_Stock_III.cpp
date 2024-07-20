/*
  給定n天的股價，求透過至多兩次的交易可得的最大利潤

  從左至右找最低買入點，從右至左找最高賣出點，某一天的利潤相當於左側交易加上右側交易所得利潤和
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxPrice = prices[n - 1];
        int maxProfit = 0;
        vector<int> left(n, 0), right(n, 0);
        for (int i = 1 ; i < n ; i++) { // from left to right
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
            left[i] = maxProfit;
        }
        maxProfit = 0;
        for (int i = n - 2 ; i >= 0 ; i--) { // from right to left
            if (prices[i] > maxPrice) {
                maxPrice = prices[i];
            }
            if (maxPrice - prices[i] > maxProfit) {
                maxProfit = maxPrice - prices[i];
            }
            right[i] = maxProfit;
        }
        maxProfit = 0;
        for (int i = 0 ; i < n ; i++) {
            maxProfit = max(maxProfit, left[i] + right[i]);
        }
        return maxProfit;
    }
};
