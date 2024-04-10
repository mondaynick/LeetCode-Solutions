/*
  輸入一個包含非負整數的陣列nums代表一排氣球，nums[i]表示第i顆氣球的分數，現在要戳破所有的氣球，
  請計算最多可能獲得多少分數，分數計算規則如下：
  當戳破第i個氣球時，可以獲得nums[i - 1] * nums[i] * nums[i + 1]的分數，且假設nums[-1]和
  nums[len(nums)]都是虛擬氣球，它們的值都是1

  利用動態規劃以斜向尋訪
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> points (nums.size() + 2, 1);
        vector<vector<int>> dp (nums.size() + 2, vector<int>(nums.size() + 2, 0));
        for (int i = 1 ; i <= nums.size() ; i++) points[i] = nums[i - 1];

        for (int i = 1 ; i < nums.size() + 2 ; i++) {
            for (int j = 0, k = i ; k < nums.size() + 2 ; j++, k++) {
                for (int l = j + 1 ; l < k ; l++) {
                    dp[j][k] = max(dp[j][k], dp[j][l] + dp[l][k] + points[j] * points[l] * points[k]);
                }
            }
        }

        return dp[0][nums.size() + 1];
    }
};
