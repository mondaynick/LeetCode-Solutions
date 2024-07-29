/*
  給定字串s和p，s代表文字，p代表模式串，判斷模式串p是否能夠匹配文字s，
  其中.可以匹配任意一個字元，*則是可以匹配任意數量的字元(包含零次)
  例如："a*"可以匹配"aa"或者是"ab"，"a?b"可以匹配"anb"，"*"可以匹配任何文字

  利用雙指標分別指向s和p的開頭，定義dp(s, i, p, j)代表s[i...]是否可以匹配p[j...]
  若s[i] == p[j]或者是p[j] == '.'，則分為以下兩種情形：
    當p[j + 1]為萬用字元*時，則p[j]可能匹配0個或多個字元
    反之則常規比對一次
  反之s[i] != p[j]且p[j] != '.'，則分為以下兩種情形：
    當p[j + 1]為萬用字元*時，則萬用字元匹配0個字元
    反之則無法繼續比對
  當j走到結尾時，檢查i是否也走到結尾，若是則回傳true
  當i走到結尾時，檢查j後面是否皆為*，若是則回傳true
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;
        for (int i = 1 ; i <= n ; i++) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }

        for (int i = 1 ; i <= m ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};
