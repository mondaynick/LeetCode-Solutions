/*
  給定一字串，在可刪除最多一字元的情況下，判斷是否為回文

  利用two pointer，一個從頭、一個從尾，當發生start, end不相等時，在比對start+1, end還是start, end-1，若再發生錯誤則回傳false
 */

class Solution {
public:
    bool isValid(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            } else {
                start++, end--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while (start <= end) {
            if (s[start] != s[end]) {
                return isValid(s, start + 1, end) | isValid(s, start, end - 1);
            } else {
                start++, end--;
            }
        }
        return true;
    }
};
