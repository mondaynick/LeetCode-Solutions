/*
  給定一系列元素，求其所有排列之結果

  利用two pointer法，迭代並交換
 */

class Solution {
public:
    void perm(vector<vector<int>>& arr, vector<int> nums, int start) {
        if (start >= nums.size()) {
            arr.push_back(nums);
        } else {
            for (int i = start ; i < nums.size() ; i++) {
                swap(nums[start], nums[i]);
                perm(arr, nums, start + 1);
                swap(nums[start], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> arr;
        perm(arr, nums, 0);
        return arr;
    }
};
