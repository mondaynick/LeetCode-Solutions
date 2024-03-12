/*
  給定一字串，回傳最小長度的子字串且該字串含有t中所有字母

  利用sliding window技術，先移動右指標直到包含t中所有字母，再移動左指標直到不包含t中所有字母，
  記錄每次找到的答案，回傳其長度最小者
 */

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        unordered_map<char, int> window, need;
        for (char c: t) need[c]++;

        int left = 0, right = 0, count = 0;
        int start = 0, len = INT_MAX;
        while (right < s.length()) {
            if (need.count(s[right])) {
                window[s[right]]++;
                if (window[s[right]] == need[s[right]]) {
                    count++;
                }
            }
            right++;

            while (count == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                if (need.count(s[left])) {
                    if (window[s[left]] == need[s[left]]) {
                        count--;
                    }
                    window[s[left]]--;
                }
                left++;
            }
        }
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};
