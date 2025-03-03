/*
  給定一個陣列 nums 和整數 pivot ，將其中元素小於pivot的元素放到前面，其餘放後面，且其順序不變

  利用 two pointer，最後再將大於 pivot 的部分反轉
 */

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int left = 0, right = nums.size() - 1;
        vector<int> res(nums.size());
        for (int ite: nums) {
            if (ite < pivot) {
                res[left++] = ite;
            } else if (ite > pivot) {
                res[right--] = ite;
            }
        }
        for (int i = left ; i <= right ; i++) {
            res[i] = pivot;
        }
        reverse(res.begin() + right + 1, res.end());
        return res;
    }
};
