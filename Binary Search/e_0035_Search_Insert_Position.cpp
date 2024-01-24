/*
  給定陣列nums，其數值為由升冪排序，輸出若要插入整數target，應該插入nums的第幾個位置

  利用二分搜尋法，當兩者交錯時回傳low
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums.back()) return nums.size();
        int low = 0, high = nums.size();
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
