/*
  給定一個整數陣列 nums ，回傳其中有多少個子陣列其元素皆為 0

  如果有連續 n 個位置的元素皆為 0 ，則可以組成 1 + 2 + ... + n 個子陣列其元素皆為 0
 */

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        long long temp = 0;
        for (long long num : nums) {
            if (num == 0) {
                ++temp;
                res += temp;
            } else {
                temp = 0;
            }
        }
        return res;
    }
};
