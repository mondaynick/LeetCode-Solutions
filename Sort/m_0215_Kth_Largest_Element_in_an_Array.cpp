/*
  給定一陣列，求第k大的數字

  利用快速排序的觀念
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        function <int(int, int)> select = [=, &nums] (int start, int end) {
            int pivot = nums[start];
            int left = start + 1, right = end;
            while (left <= right) {
                if (nums[left] < pivot && nums[right] > pivot) swap(nums[left++], nums[right--]);
                if (nums[left] >= pivot) left++;
                if (nums[right] <= pivot) right--;
            }
            swap(nums[start], nums[right]);
            return right;
        };
        int l = 0, r = nums.size() - 1;
        while (true) {
            int pos = select(l, r);
            if (pos == k - 1) {
                return nums[pos];
            } else if (pos > k - 1) {
                r = pos - 1;
            } else {
                l = pos + 1;
            }
        }
    }
};
