/*
  給定一陣列，將其升冪排序

  利用快速排序
 */

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function<void(int, int)> quickSort = [&](int start, int end) {
            if (start >= end) return;
            int left = start, right = end;
            int idx = start + (rand() % (end - start + 1));
            int pivot = nums[idx];
            while (left <= right) {
                while (nums[left] < pivot) left++;
                while (nums[right] > pivot) right--;
                if (left <= right) swap(nums[left++], nums[right--]);
            }
            quickSort(start, right);
            quickSort(left, end);
        };
        quickSort(0, nums.size() - 1);
        return nums;
    }
};
