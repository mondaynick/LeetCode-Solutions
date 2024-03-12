/*
  給定兩字串s1和s2，若s1存在排列為s2的子字串，則回傳true，反之則回傳false

  利用sliding window技術
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> dict;
        for (char c: "abcdefghijklmnopqrstuvwxyz") dict[c] = 0;
        for (char c: s1) dict[c]++;

        int s1len = s1.length(), s2len = s2.length();
        int left = 0, right = 0, count = s1len;
        while (right < s2len) {
            if (dict[s2[right]] > 0) count--;
            dict[s2[right]]--;
            right++;

            if (count == 0) return true;
            if (right - left == s1len) {
                dict[s2[left]]++;
                if (dict[s2[left]] > 0) count++;
                left++;
            }
        }
        return false;
    }
};
