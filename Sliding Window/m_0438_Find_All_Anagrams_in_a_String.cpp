/*
  給定s和p，回傳s存在p中的排列子字串之開始索引

  利用sliding window技術
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window, need;
        for (char c: p) need[c]++;
        vector<int> res;

        int left = 0, right = 0, count = 0;
        while (right < s.length()) {
            if (need.count(s[right])) {
                window[s[right]]++;
                if (window[s[right]] == need[s[right]]) {
                    count++;
                }
            }
            right++;

            while (right - left >= p.length()) {
                if (count == need.size()) res.push_back(left);
                if (need.count(s[left])) {
                    if (window[s[left]] == need[s[left]]) {
                        count--;
                    }
                    window[s[left]]--;
                }
                left++;
            }
        }

        return res;
    }
};
