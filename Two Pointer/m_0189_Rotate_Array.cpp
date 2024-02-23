/*
  給定一陣列和一數字，回傳將該陣列循環右移k位之結果

  架設nums = [1, 2, 3, 4, 5, 6, 7], k = 3
  先翻轉前面n - k 個數字，再翻轉後面k個數字，最後再翻轉全部的數字
   1 2 3 4 5 6 7
  [4  3  2  1] 5  6  7
   4  3  2  1 [7  6  5]
  [1  2  3  4  5  6  7]
 */

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            nums[start] = nums[start] ^ nums[end];
            nums[end] = nums[start] ^ nums[end];
            nums[start] = nums[start] ^ nums[end];
            start++, end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;

        int n = nums.size();
        k %= n;

        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};
