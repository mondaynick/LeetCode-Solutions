/*
  輸出含有n個節點的binary search tree數量

  從第1個到第n個開始算，若含有i個節點，且左子樹有j個節點，則右子樹有i - j - 1個節點，方法數為相乘
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp (n+1, 0);
        dp[0] = 1;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 0 ; j < i ; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
