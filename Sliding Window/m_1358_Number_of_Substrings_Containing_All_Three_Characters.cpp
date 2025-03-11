/*
  給定字串 s ，且字串 s 只會出現 'a', 'b', 'c' 三種字元，求字串 s 中共有多少個子字串 'a', 'b', 'c' 皆有出現
  
  利用 sliding window
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0, res = 0, count = 0;
        int len = s.length();
        unordered_map<char, int> memo;
        for (; left < len ; left++) {
            while (right < len && count < 3) {
                char rc = s[right];
                memo[rc]++;
                if (memo[rc] == 1) count++;
                right++;
            }
            if (count == 3) {
                res += len - right + 1;
            }
            char lc = s[left];
            memo[lc]--;
            if (memo[lc] == 0) count--;
        }
        return res;
    }
};
