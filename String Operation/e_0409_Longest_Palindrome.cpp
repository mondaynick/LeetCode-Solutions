/*
  給定一字串，求其任意排列可構成的最大回文子字串長度，如：abccccdd可構成長度最大為7的回文字串dccaccd

  利用字典記錄所有字母出現過的次數，在記錄成雙的有幾隊，在記錄遇到奇數的狀況
 */

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> dict;
        for (auto c: s) {
            if (dict.find(c) != dict.end()) dict[c]++;
            else dict[c] = 1;
        }
        int length = 0;
        for (auto c: dict) {
            length += ((int)c.second / 2) * 2;
        }
        for (auto c: dict) {
            if (c.second % 2 == 1) {
                length++;
                break;
            }
        }
        return length;
    }
};
