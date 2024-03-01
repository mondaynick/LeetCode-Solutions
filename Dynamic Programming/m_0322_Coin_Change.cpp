/*
  給定coins代表一系列的錢幣面額，假設所有面額的錢皆有無限多個．求利用這些面額要拿到amount金額最少所需多少枚硬幣

  欲求第i元用k面額的錢幣，相當於求1 + 第i - k元
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        vector<int> dp (amount + 1, 0);
        for (int i = 1 ; i <= amount ; i++) {
            int minValue = INT_MAX;
            for (auto c: coins) {
                if (i - c < 0 || dp[i - c] == -1)
                    continue;
                minValue = min(minValue, 1 + dp[i - c]);
            }
            dp[i] = (minValue == INT_MAX) ? -1 : minValue;
        }

        return dp[amount];
    }
};
