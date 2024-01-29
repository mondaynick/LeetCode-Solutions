/*
  給定一陣列，輸出一陣列滿足每個元素為對應原陣列索引其餘元素之積，e.g.
    輸入：[2, 3, 4, 5]
    輸出：[3*4*5, 2*4*5, 2*3*5, 2*3*4] = [60, 40, 30, 24]
  確保時間複雜度為O(n)且不要使用除法

  從左邊遍歷再從右邊遍歷
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        for (int i = 1 ; i < len ; i++) {
            res[i] = nums[i - 1] * res[i - 1];
        }
        for (int i = len - 2 ; i >= 0 ; i--) {
            nums[i] *= nums[i + 1];
            res[i] *= nums[i + 1];
        }
        return res;
    }
};
