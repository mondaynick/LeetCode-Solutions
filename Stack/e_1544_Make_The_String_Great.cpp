/*
  給定一字串，若相鄰兩字元s[i]和s[i + 1]中存在一個為大寫一個為小寫且皆代表相同英文字母，則消除這兩個字元，
  回傳消除後的字串

  利用堆疊
 */

class Solution {
public:
    string makeGood(string s) {
        stack<char> S;
        for (auto c: s) {
            if (S.empty() || abs(S.top() - c) != 32) {
                S.push(c);
            } else {
                S.pop();
            }
        }
        string res = "";
        while (!S.empty()) {
            res += S.top();
            S.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
