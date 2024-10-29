/*
  給定一個整數n，將它拆分成k個正整數的和，其中k>=2，找到可使這些
  拆分出的整數乘積最大的拆分方法
  
    DP[i]              (i <- 2 ~ n)
   /     \
  /       \
  j        DP[i - j]   (j <- 1 ~ i - 1)
  j        i - j
 */

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 2 ; i <= n ; i++) {
            int res = INT_MIN;
            for (int j = 1 ; j < i ; j++) {
                int temp = max(i - j, dp[i - j]);
                res = max(res, j * temp);
            }
            dp[i] = res;
        }
        return dp.back();
    }
};
