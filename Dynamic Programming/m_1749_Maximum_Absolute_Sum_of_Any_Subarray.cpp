/*
  給定一個矩陣 nums ，回傳其 subarray 使得各項元素和之絕對值為最大

  利用前綴和，將全局最大扣掉全局最小
 */

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int presum = 0, locmin = 0, locmax = 0;
        for (auto ite: nums) {
            presum += ite;
            locmin = min(locmin, presum);
            locmax = max(locmax, presum);
        }
        return locmax - locmin;
    }
};
