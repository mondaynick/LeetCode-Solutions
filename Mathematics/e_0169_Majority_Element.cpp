/*
  給定一系列數字，求該數字數量超過半數之數字

  利用摩爾投票算法(Boyer-Moore Majority Vote Algorithm)：
    1. 令majority = 任意數, count = 0
    2. 遍歷nums從第一個到最後一個
        若nums[i] = majority
          count++
        反之
          若count > 0
            count--
          反之
            majority = nums[i]
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0, count = 0;
        for (auto n: nums) {
            if (n == majority) {
                count++;
            } else {
                if (count > 0) {
                    count--;
                } else {
                    majority = n;
                }
            }
        }
        return majority;
    }
};
