/*
  給定一陣列，回傳最終結果如下
  1    2    3    4    5
    3    5    7    9
       8    2    6
         0    8
            8

  若目前陣列有n個元素，則建立一個大小為n-1的陣列，並更新所有元素，
  重複以上步驟，直到陣列只剩一個元素為止
 */

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() != 1) {
            vector<int> temp(nums.size() - 1, 0);
            for (int i = 0 ; i < nums.size() - 1 ; i++) {
                temp[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums = temp;
        }
        return nums[0];
    }
};
