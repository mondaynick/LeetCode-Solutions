/*
  給定一序列，回傳其最大遞增子序列

  給定初始條件dp[0] = 1，假設num[5] = 3，只要找到前面那些結尾比3還要小的子序列，
  然後把3放到後面，就能形成一個新的遞增子序列，而且這個新的遞增子序列長度加一，
  從選定的這些遞增子序列當中，選取一個長度最大的即為dp[5]
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 1;

        vector<int> dp (len, 1);
        for (int i = 1 ; i < len ; i++) {
            for (int j = 0 ; j < i ; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
