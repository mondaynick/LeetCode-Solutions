/*
  給定兩個陣列，若兩陣列元素相同則建立一條連線，求最大連線並滿足線之間不相交

  相當於求longest common subsequence
 */

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int rows = nums1.size(), cols = nums2.size();
        vector<vector<int>> dp (rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1 ; i <= rows ; i++) {
            for (int j = 1 ; j <= cols ; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[rows][cols];
    }
};
