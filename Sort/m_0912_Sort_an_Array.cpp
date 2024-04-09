/*
  給定一陣列，將其升冪排序

  利用快速排序
 */

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function <void(int, int)> quickSort = [&] (int start, int end) {
            if (start < end) {
                /* Randomize the Pivot */
                int idx = start + rand() % (end - start + 1);
                swap(nums[idx], nums[start]);

                /* Hoare Partition Scheme */
                int pivot = nums[start], left = start + 1, right = end;
                while (left <= right) {
                    while (left <= right && nums[left] <= pivot) left++;
                    while (left <= right && nums[right] >= pivot) right--;
                    if (left <= right) swap(nums[left], nums[right]);
                }
                swap(nums[start], nums[right]);

                /* Recursion */
                quickSort(start, right - 1);
                quickSort(right + 1, end);
            }
        };
        quickSort(0, nums.size() - 1);
        return nums;
    }
};
