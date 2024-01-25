/*
  給定一字串，輸出是否為回文

  two pointer，一個從頭、一個從尾
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            } else {
                start++, end--;
            }
        }
        return true;
    }
};
