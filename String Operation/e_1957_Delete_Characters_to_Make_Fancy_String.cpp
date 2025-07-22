/*
  給定一個字串 s ，fancy string 的定義為不出現任意三個連續相同的字母，刪除 s 的一些字元使其成為 fancy string

  根據題意求得
 */

class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for (char c : s) {
            if (res.length() >= 2 && res.back() == c && res[res.length() - 2] == c) {
                continue;
            } else {
                res += c;
            }
        }
        return res;
    }
};
