/*
  給定n天的股價，求透過無限多次的交易可得的最大利潤，但每次賣出後的隔天進入冷卻一天(即不可進行買入)

  若第i天沒有持股，有兩種可能性，取可獲得最大利潤的可能性：
    (1) 第i - 1天就沒有持股
    (2) 第i - 1天有持股但第i天賣掉
  若第i天有持股，有兩種可能性，取可獲得最大利潤的可能性：
    (1) 第i - 1天就有持股
    (2) 第i - 1天為冷卻但第i天買入
  若第i天為冷卻，有兩種可能性，取可能獲得最大利潤的可能性：
    (1) 第i - 1天也為冷卻
    (2) 第i - 1天賣出
  最後一天取沒有持股為答案，因為要獲得最大利潤最後一天之後必沒有持股
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int holdShare = -prices[0], noShare = 0, cooldown = 0;

        for (int i = 1 ; i < prices.size() ; i++) {
            holdShare = max(holdShare, cooldown - prices[i]);
            cooldown = max(cooldown, noShare);
            noShare = max(noShare, holdShare + prices[i]);
        }

        return noShare;
    }
};
