/*
  假設有一個鍵盤只有四個按鍵，其中分別是：
      A：在螢幕上顯示一個A
      Ctrl-A：選中整個螢幕
      Ctrl-C：將選中的區域複製到緩衝區
      Crtl-V：將緩衝區的內容輸出到游標所在的螢幕位置
  輸入操作的次數，輸出在這些操作次數內螢幕上最多能顯示幾個字元

  對於第i次操作而言，計算按A鍵還是按Ctrl+V鍵會得到最大的結果
 */

class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1 ; i <= n ; i++) {
            // Press A
            dp[i] = dp[i - 1] + 1;
            // Press Ctrl+V
            for (int j = 2 ; j < i ; j++) {
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
            }
        }

        return dp[n];
    }
};
