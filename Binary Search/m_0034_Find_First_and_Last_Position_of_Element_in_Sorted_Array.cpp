/*
  給定一排序好的陣列及target，求target在該陣列的第一個和最後一個元素，若不存在則回傳-1

  找左側邊界往左靠攏，找右側邊界往右靠攏
 */

class Solution {
public:
    int bound(vector<int> nums, int target, bool isLeft) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                if (isLeft) right = mid;
                else        left = mid + 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (isLeft)
            if (left == nums.size()) return -1;
            else return (nums[left] == target) ? left : -1;
        else
            if (left == 0) return -1;
            else return (nums[left - 1] == target) ? left - 1 : -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBound = bound(nums, target, true);
        int rightBound = bound(nums, target, false);
        return {leftBound, rightBound};
    }
};
