/*
  給定一個陣列 nums ，回傳陣列中的數字有多少個具有偶數個位數

  先利用 log10 取得該數的位數個數(會少1)，再利用 &1 去判斷是否為偶數
 */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto num: nums) {
            res += (int)log10(num) & 1;
        }
        return res;
    }
};
