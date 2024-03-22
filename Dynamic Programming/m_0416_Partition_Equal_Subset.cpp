/*
  給定一個只包含正整數的非空陣列nums，回傳該陣列是否可以分割成兩個子集使得兩個子集的元素和相等

  若nums的元素總和為奇數，代表nums無法分割成兩個子集使得兩個子集的元素和相等
  否則建立dp二維陣列，base case為dp[...][0]為true，因為當背包沒有空間時，相當於背包滿了
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % 2 == 1) return false;
        sum /= 2;

        vector<vector<bool>> dp (nums.size() + 1, vector<bool>(sum + 1, false));
        for (int i = 0 ; i <= nums.size() ; i++) dp[i][0] = true;

        for (int i = 1 ; i <= nums.size() ; i++) {
            for (int j = 1 ; j <= sum ; j++) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[nums.size()][sum];
    }
};
