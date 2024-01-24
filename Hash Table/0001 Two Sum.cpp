// https://leetcode.com/problems/two-sum/

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
