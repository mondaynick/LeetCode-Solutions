/*
  給定一陣列，陣列中只有一個數字會出現恰好一次，其餘則會出現恰好三次，回傳其出現一次的數字

  當初始時，num = n, one = 0, two = 0，執行以下計算：
    one = (one ^ num) & ~two
    two = (two ^ num) & ~one
  當執行第1次時：one = n, two = 0
  當執行第2次時：one = 0, two = n
  當執行第3次時：one = 0, two = 0
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int num: nums) {
            one = (one ^ num) & ~two;
            two = (two ^ num) & ~one;
        }
        return one;
    }
};
