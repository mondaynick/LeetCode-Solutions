/*
  給定一陣列，求陣列中出現頻率最多的數字共有幾個

  第一次遍歷陣列，看出現頻率最多為幾次並記錄每個數字出現幾次
  第二次遍歷字典，若數字出現頻率等於最大出現頻率則計算
 */

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxCount = 0;
        unordered_map<int, int> dict;

        for (auto n: nums) {
            if (dict.find(n) == dict.end()) {
                dict[n] = 1;
            } else {
                dict[n]++;
            }
            if (dict[n] > maxCount) maxCount = dict[n];
        }

        int count = 0;
        for (auto d: dict) {
            if (d.second == maxCount) {
                count += d.second;
            }
        }
        return count;
    }
};
