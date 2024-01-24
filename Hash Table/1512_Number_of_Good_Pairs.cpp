/*
  給定陣列nums，輸出good pair的數量，good pair定義如下：nums[i]==num[j] && i < j

  使用字典，遍歷nums，計算每個元素出現的數量並加到res後回傳
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        map<int, int> dict;

        for (int i = 0 ; i < nums.size() ; i++) {
            if (dict.find(nums[i]) == dict.end()) {
                dict[nums[i]] = 0;
            } else {
                res += ++dict[nums[i]];
            }
        }
        return res;
    }
};
