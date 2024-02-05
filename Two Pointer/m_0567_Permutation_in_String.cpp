/*
  給定兩字串s1和s2，若s1存在排列為s2的子字串，則回傳true，反之則回傳false

  利用sliding window技術
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> dict;
        for (auto c: "abcdefghijklmnopqrstuvwxyz") dict[c] = 0;
        for (auto c: s1) dict[c]++;

        int l = 0, r = 0, count = s1.length();
        while (r < s2.length()) {
            if (dict[s2[r]] > 0) count--;
            dict[s2[r]]--;
            r++;
            if (count == 0) return true;
            if (r - l == s1.length()) {
                if (dict[s2[l]] >= 0) count++;
                dict[s2[l]]++;
                l++;
            }
        }
        return false;
    }
};
