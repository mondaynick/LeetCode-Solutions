/*
  輸入一個有序的陣列，要求原地刪除重複的元素，使得每一個元素只出現一次，並返回去掉重複後新陣列的長度

  利用two pointer
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int slow = 0, fast = 1;
        while (fast < len) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};
