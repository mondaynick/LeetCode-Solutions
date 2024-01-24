/*
    給定串列nums和整數target，欲求索引i, j使得nums[i]+nums[j]等於target
    
    遍歷nums，若目前指到第i個，
    若target - nums[i]在字典中，則回傳其對應的value，
    反之則儲存鍵值對{target-nums[i], i}至字典中
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> dict;
        vector <int> ans;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (dict.find(nums[i]) == dict.end()) {
                dict[target - nums[i]] = i;
            } else {
                ans.push_back(dict[nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};
