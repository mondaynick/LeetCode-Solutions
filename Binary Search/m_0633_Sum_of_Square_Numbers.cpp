/*
  給定一整數，判斷該整數是否為兩平方數相加

  利用binary search
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = sqrt(c);
        while (left <= right) {
            long sop = (long)(left * left) + (long)(right * right);
            if (sop == c) {
                return true;
            } else if (sop < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};
