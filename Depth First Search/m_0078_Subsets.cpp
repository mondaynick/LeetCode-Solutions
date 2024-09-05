/*
  給定一陣列，返回其冪集合

  利用dfs
 */

class Solution {
public:
    void handler(vector<vector<int>>& res, vector<int> nums, vector<int> temp, int start) {
        if (start > nums.size()) return;
        res.push_back(temp);
        for (int i = start ; i < nums.size() ; i++) {
            temp.push_back(nums[i]);
            handler(res, nums, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        handler(res, nums, {}, 0);
        return res;
    }
};
