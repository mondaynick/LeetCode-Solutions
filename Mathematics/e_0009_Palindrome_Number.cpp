/*
  給定一數字，求將該數字是否回文(負數必定不回文，因為-101不等於101-)

  利用除法和取餘數
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long temp = x, reverse = 0;
        while (temp) {
            reverse *= 10;
            reverse += temp % 10;
            temp /= 10;
        }
        return reverse == x;
    }
};
