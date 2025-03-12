/*
  給定一陣列 nums ，其中 nums 的元素為遞增排序，回傳 nums 中為正數和負數的元素數量之最大值，記得 0 不為正數也不為負數

  利用 binary search
 */

class Solution {
private:
    int lastNeg(vector<int> nums) {
        int left = -1, right = nums.size();
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return (left == -1) ? -1 : left;
    }
    int firstPos(vector<int> nums) {
        int left = -1, right = nums.size();
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= 0) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return (right == nums.size()) ? -1 : right;
    }
public:
    int maximumCount(vector<int>& nums) {
        int lastNegIdx = lastNeg(nums);
        int numOfNeg = (lastNegIdx == -1) ? 0 : (lastNegIdx + 1);
        int firstPosIdx = firstPos(nums);
        int numOfPos = (firstPosIdx == -1) ? 0 : (nums.size() - firstPosIdx);
        return max(numOfNeg, numOfPos);
    }
};
