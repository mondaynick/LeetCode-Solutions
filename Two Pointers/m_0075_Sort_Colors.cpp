/*
  給定一陣列，0代表紅色、1代表白色、2代表藍色，利用in-place演算法將陣列排成紅色在最左邊、白色在最中間、藍色在最右邊

  利用two pointer法
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        for (int i = 0 ; i <= blue ; i++) {
            if (nums[i] == 0) {
                nums[i] = nums[red];
                nums[red++] = 0;
            } else if (nums[i] == 2) {
                nums[i--] = nums[blue];
                nums[blue--] = 2;
            }
        }
    }
};
