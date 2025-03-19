/*
  給定一個陣列 nums ，其中 nums 的數字只會有 0 和 1 ，每次可取連續三個相鄰的數字去做翻轉，
  即 0 變成 1 且 1 變成 0 ，回傳將 nums 中所有數字都被翻轉成 1 的所需次數，若無法翻轉成此
  情況則回傳 -1

  利用 sliding window
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int left = 0, count = 0;
        int len = nums.size();
        for (; left < len - 2 ; left++) {
            if (nums[left] == 0) {
                nums[left] ^= 1;
                nums[left + 1] ^= 1;
                nums[left + 2] ^= 1;
                count++;
            }
        }
        for (int num: nums) {
            if (num == 0) return -1;
        }
        return count;
    }
};
