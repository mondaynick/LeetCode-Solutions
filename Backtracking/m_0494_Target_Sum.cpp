/*
  給定一個非負整數陣列nums及一個目標值target，針對每個元素nums[i]可以加上正號或負號，請計算共有幾種符號的組合，
  使得nums中元素的和為target

  利用backtracking
 */

class Solution {
public:
    unordered_map<string, int> memo;

    int dfs(vector<int> nums, int i, int rest) {
        if (i == nums.size()) {
            if (rest == 0) return 1;
            else return 0;
        }
        string key = to_string(i) + "," + to_string(rest);
        if (memo.count(key)) {
            return memo[key];
        } else {
            int res = dfs(nums, i + 1, rest - nums[i]) + dfs(nums, i + 1, rest + nums[i]);
            return memo[key] = res;
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, 0, target);
    }
};
