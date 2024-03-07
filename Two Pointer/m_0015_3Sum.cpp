/*
  給定一個串列，輸出任三個位置數字和等於target的所有可能，答案以索引表示，且解的索引不可重複

  先將nums排序，令最左邊的數字為x，逐漸往右移動，代表剩下兩數的和要為-x，
  將x右邊剩下的數字，令最左邊為u，最右邊為v，
  若u + v == x，紀錄答案，
  若u + v < x，u++，
  若u + v > x，v--，
  移動指標時若下一個數字與目前相同則跳過，直到移動到不同為止
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0 ; i < len - 2 ; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int j = i + 1, k = len - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        res.push_back({nums[i], nums[j], nums[k]});
                        j++, k--;
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    } else if (sum < 0) {
                        j++;
                        while (j < k && nums[j] == nums[j - 1]) j++;
                    } else {
                        k--;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    }
                }
            }
        }
        return res;
    }
};
