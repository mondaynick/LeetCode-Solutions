/*
  給定一個串列，輸出任三個位置數字和等於target的所有可能，答案以索引表示，且解的索引不可重複

  此題和3Sum解法類似，只在於需注意若答案無解需回傳空串列，且陣列中的數字相加有可能會產生overflow
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;

        if (nums.size() < 4) return res;

        for (int i = 0 ; i < len - 3 ; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                for (int j = i + 1 ; j < len - 2 ; j++) {
                    if (j == i + 1 || nums[j] != nums[j - 1]) {
                        int k = j + 1, l = len - 1;
                        while (k < l) {
                            long sum = (long)(nums[i] + nums[j]) + (long)(nums[k] + nums[l]);
                            if (sum == target) {
                                res.push_back({nums[i], nums[j], nums[k], nums[l]});
                                k++, l--;
                                while (k < l && nums[k] == nums[k - 1]) k++;
                                while (k < l && nums[l] == nums[l + 1]) l--;
                            } else if (sum < target) {
                                k++;
                                while (k < l && nums[k] == nums[k - 1]) k++;
                            } else {
                                l--;
                                while (k < l && nums[l] == nums[l + 1]) l--;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
