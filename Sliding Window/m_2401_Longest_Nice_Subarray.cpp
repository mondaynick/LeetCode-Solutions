/*
  給定一個整數陣列 nums ，回傳其子陣列為 nice 子陣列的最大長度， nice 子陣列的定義為任兩個元素其 and 之值為 0

  利用 sliding window ，定義 nowMask 為所有元素 or 之值，故 nowMask 的每一個 1 必定來自子陣列任一個數字，
  右邊界往右移動直到出現重複使得子陣列不為 nice 的情況，再將左邊界往右移動直到子陣列為 nice 的情況
 */

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLen = 0, nowMask = 0, nowLen = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            while (nowMask & nums[i]) {
                nowMask ^= nums[i - nowLen];
                nowLen--;
            }
            nowMask |= nums[i];
            nowLen++;
            maxLen = max(maxLen, nowLen);
        }
        return maxLen;
    }
};
