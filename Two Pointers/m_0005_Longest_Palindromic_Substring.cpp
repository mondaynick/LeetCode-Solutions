/*
  給定一個字串s，返回該字串中最長的回文子字串

  利用two pointers
 */

class Solution {
public:
    string palindrome(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string res;
        for (int i = 0 ; i < s.length() ; i++) {
            string odd = palindrome(s, i, i);
            string even = palindrome(s, i, i + 1);
            if (odd.length() > res.length()) res = odd;
            if (even.length() > res.length()) res = even;
        }
        return res;
    }
};
