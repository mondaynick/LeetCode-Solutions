/*
  給定一數字，求其二進位共有幾個1

  利用移位與AND運算迭代求得
 */

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            if (n & 1) count++;
            n >>= 1;
        }
        return count;
    }
};
