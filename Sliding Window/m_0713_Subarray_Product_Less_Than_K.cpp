/*
  給定一陣列，回傳所有子陣列其乘積小於k的所有可能數

  利用sliding window
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int left = 0, right = 0, product = 1, count = 0;
        while (right < nums.size()) {
            product *= nums[right];

            while (product >= k) {
                product /= nums[left];
                left++;
            }

            count += right - left + 1;
            right++;
        }

        return count;
    }
};
