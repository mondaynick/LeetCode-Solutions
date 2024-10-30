/*
  給定一整數n，回傳其0到n的二進位分別有多少個1，
  如：輸入4，則輸出[0, 1, 1, 2, 1]

  利用動態規劃，給定初始條件，dp[0] = 0，dp[1] = 1，
  對於dp[i]而言，將i分為i的LSB(i % 2)和其餘的bit(i / 2)，
  從已算過的dp中找到對應1的個數並相加
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 0) return dp;
        dp[1] = 1;
        for (int i = 2 ; i <= n ; i++) {
            dp[i] = dp[i / 2] + dp[i % 2];
        }
        return dp;
    }
};
