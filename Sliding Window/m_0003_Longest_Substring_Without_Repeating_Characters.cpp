/*
  輸入一個字串s，回傳s中不包含重複字元的最長字串長度
  
  利用sliding window技術
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dict;
        int left = 0, right = 0, res = 0;

        while (right < s.length()) {
            char c = s[right];
            dict[c]++;
            right++;

            while (dict[c] > 1) {
                dict[s[left]]--;
                left++;
            }

            res = max(res, right - left);
        }
        return res;
    }
};
