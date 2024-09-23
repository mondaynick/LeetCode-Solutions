/*
  給定一系列的數字，將0全部往最後面移動，如給定[0, 1, 0, 3, 12]，則變成[1, 3, 12, 0, 0]

  利用雙指標，先指向第一個為0，再從該處往下找第一個不為0，交換，重複以上步驟
  0 1 0 3 12
  ^ ^
  s e

  1 0 0 3 12
    ^   ^
    s   e

  1 3 0 0 12
      ^   ^
      s   e

  1 3 12 0 0
         ^   ^
         s   e
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, end, size = nums.size();
        while (true) {
            while (nums[start] != 0) {
                start++;
                if (start >= size) return;
            }
            end = start;
            while (nums[end] == 0) {
                end++;
                if (end >= size) return;
            }
            swap(nums[start], nums[end]);
            start++;
        }
    }
};
