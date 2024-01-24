/*
  給定一字串s，求其最大前後綴相同長度

  建立failure function：
  (1) 若s[index] == s[prefixLen]，則failure[index] = ++prefixLen
  (2) 若s[index] != s[prefixLen]且prefixLen > 0，則prefixLen = failure[prefixLen - 1]
  (3) 若s[index] != s[prefixLen]且prefixLen == 0，則failure[index] = 0
 */

class Solution {
public:
    string longestPrefix(string s) {
        int prefixLen = 0, index = 1;
        vector<int> failure (s.size(), 0);
        while (index < s.size()) {
            if (s[index] == s[prefixLen]) {
                failure[index++] = ++prefixLen;
            } else {
                if (prefixLen > 0) {
                    prefixLen = failure[prefixLen - 1];
                } else {
                    failure[index++] = 0;
                }
            }
        }
        return s.substr(0, failure[s.size() - 1]);
    }
};
