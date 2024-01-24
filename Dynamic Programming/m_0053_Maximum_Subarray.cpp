/*
  給定一個陣列，求最大連續元素和

  若當前元素之前一個元素為負數則不加上前一個元素，反之加上
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        int maxima;
        dp[0] = maxima = nums[0];

        for (int i = 1 ; i < len ; i++) {
            dp[i] = (dp[i - 1] < 0) ? (nums[i]) : (nums[i] + dp[i - 1]);
            if (dp[i] > maxima) maxima = dp[i];
        }

        return maxima;
    }
};
