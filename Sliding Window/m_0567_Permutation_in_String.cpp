/*
  給定兩字串s1和s2，若s1存在排列為s2的子字串，則回傳true，反之則回傳false

  利用sliding window技術
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> window, need;
        for (char c: s1) need[c]++;

        int left = 0, right = 0, count = 0;
        while (right < s2.length()) {
            if (need.count(s2[right])) {
                window[s2[right]]++;
                if (window[s2[right]] == need[s2[right]]) {
                    count++;
                }
            }
            right++;

            while (right - left >= s1.length()) {
                if (count == need.size()) return true;
                if (need.count(s2[left])) {
                    if (window[s2[left]] == need[s2[left]]) {
                        count--;
                    }
                    window[s2[left]]--;
                }
                left++;
            }
        }
        return false;
    }
};
