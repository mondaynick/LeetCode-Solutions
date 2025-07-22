/*
  給定一個陣列 nums ，回傳 nums 中所有子陣列其元素和最大為何

  利用 sliding window ，若右指標和左指標匡到的範圍有含有重複的元素，才移動左指標直到範圍內
  不出現重複的元素，每次移動右指標時紀錄範圍內所有元素和
 */

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, temp = 0;
        int left = 0, right = 0;
        int len = nums.size();
        unordered_map<int, int> freq;
        while (right < len) {
            int rc = nums[right];
            ++freq[rc];
            temp += rc;
            ++right;
            if (freq[rc] == 1) { // no duplicate
                res = max(res, temp);
            } else {
                while (left < right) {
                    int lc = nums[left];
                    --freq[lc];
                    ++left;
                    temp -= lc;
                    if (freq[lc] == 1) break;
                }
            }
        }
        return res;
    }
};
