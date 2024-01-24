/*
  給定兩個數字，輸入其漢明距離

  將兩數字xor後計算其二進位表示式共有幾個1
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int temp = x ^ y;
        while (temp) {
            if ((temp & 1) == 1) count++;
            temp = temp >> 1;
        }
        return count;
    }
};
