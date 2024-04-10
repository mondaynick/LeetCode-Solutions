/*
  給定字串s和p，s代表文字，p代表模式串，判斷模式串p是否能夠匹配文字s，
  其中.可以匹配任意一個字元，*則是讓之前的字元重複任意次數
  例如：".a*b"可以匹配"zaaab"或者是"ab"，"a..b"可以匹配"amnb"，".*"可以匹配任何文字

  利用雙指標分別指向s和p的開頭，定義dp(s, i, p, j)代表s[i...]是否可以匹配p[j...]
  若s[i] == p[j]或者是p[j] == '.'，則分為以下兩種情形：
    當p[j + 1]為萬用字元*時，則p[j]可能匹配0個或多個字元
    反之則常規比對一次
  反之s[i] != p[j]且p[j] != '.'，則分為以下兩種情形：
    當p[j + 1]為萬用字元*時，則萬用字元匹配0個字元
    反之則無法繼續比對
  當j走到結尾時，檢查i是否也走到結尾，若是則回傳true
  當i走到結尾時，檢查以下兩種情況：
    如果能匹配空字串，一定是字元和*成對出現，因此先檢查(p.length() - j) % 2 == 1
    再檢查是否為x*y*z*這種形式，遍歷整個模式串
 */

class Solution {
public:
    unordered_map<string, bool> memo;

    bool dp(string s, int i, string p, int j) {
        /* 當pattern全部走完，則text也要全部走完 */
        if (j == p.length())
            return i == s.length();

        /* 當text先走完，再來看pattern剩下的是否能匹配空字串，如s = "a", t = "ab*c*"這種情況 */
        if (i == s.length()) {
            /* 若可以匹配空字串，則pattern剩下的必為偶數個字元 */
            if ((p.length() - j) % 2 == 1) return false;
            /* 檢查偶數項是否為* */
            for (; j < p.length() ; j += 2)
                if (p[j + 1] != '*') return false;
            return true;
        }

        /* 利用備忘錄記錄來消除重疊子問題 */
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];

        bool res = false;
        if (s[i] == p[j] || p[j] == '.') {
            /* 有*萬用字元，可以比對0次或多次 */
            if (j < p.length() - 1 && p[j + 1] == '*') {
                res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
            }
            /* 無*萬用字元，常規比對1次 */
            else {
                res = dp(s, i + 1, p, j + 1);
            }
        } else {
            /* 有*萬用字元，只能比對0次 */
            if (j < p.length() - 1 && p[j + 1] == '*') {
                res = dp(s, i, p, j + 2);
            }
            /* 無*萬用字元，無法比對下去 */
            else {
                res = false;
            }
        }

        memo[key] = res;
        return res;
    }

    bool isMatch(string s, string p) {
        /* 表示s[0...]和p[0...]是否能匹配 */
        return dp(s, 0, p, 0);    
    }
};
