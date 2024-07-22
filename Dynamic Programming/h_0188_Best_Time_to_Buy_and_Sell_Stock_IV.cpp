/*
  給定n天的股價，求透過至多兩次的交易可得的最大利潤

  對於第i天而言，第j筆買入有兩種情況，取其大者：
    (1) 原本已經買入j筆
    (2) 原本已經賣出j - 1筆，這次才買入
  對於第i天而言，第j筆賣出有兩種情況，取其大者：
    (1) 原本已經賣出j筆
    (2) 原本已經買入j筆，這次才賣出
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy (k, -prices[0]);
        vector<int> sell (k, 0);

        for (int i = 1 ; i < prices.size() ; i++) {
            for (int j = 0 ; j < k ; j++) {
                buy[j] = max(buy[j], ((j == 0) ? 0 : sell[j - 1]) - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }

        int res = INT_MIN;
        for (int i = 0 ; i < k ; i++) {
            if (sell[i] > res) res = sell[i];
        }
        return res;
    }
};

/*
    buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0, ...;

    buy1 = max(buy1, -prices[i]);
    sell1 = max(sell1, buy1 + prices[i]);
    buy2 = max(buy2, sell1 - prices[i]);
    sell2 = max(sell2, buy2 + prices[i]);
    ...
 */
