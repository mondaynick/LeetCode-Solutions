/*
  給定一陣列，將其升冪排序

  利用合併排序
 */

class Solution {
public:
    void conquer(vector<int>& nums, int start, int mid, int end) {
        vector<int> left(nums.begin()+start, nums.begin()+mid+1);
        vector<int> right(nums.begin()+mid+1, nums.begin()+end+1);
        int idx = start, l = 0, r = 0;
        while (l < left.size() && r <right.size()) {
            if (left[l] < right[r]) {
                nums[idx++] = left[l++];
            } else {
                nums[idx++] = right[r++];
            }
        }
        while (l < left.size()) {
            nums[idx++] = left[l++];
        }
        while (r < right.size()) {
            nums[idx++] = right[r++];
        }
    }
    void divide(vector<int>& nums, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            divide(nums, start, mid);
            divide(nums, mid+1, end);
            conquer(nums, start, mid, end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size() - 1);
        return nums;
    }
};
