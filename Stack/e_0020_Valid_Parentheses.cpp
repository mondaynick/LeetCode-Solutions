/*
  給定一個有小、中、大括弧所組成的字串，確認該括弧組成是否合法

  利用堆疊
 */

class Solution {
public:
    bool isValid(string s) {
        stack <char> S;
        for (auto c: s) {
            switch(c) {
                case '(':
                case '[':
                case '{':
                    S.push(c);
                    break;
                case ')':
                    if (S.empty() || S.top() != '(') return false;
                    S.pop();
                    break;
                case ']':
                    if (S.empty() || S.top() != '[') return false;
                    S.pop();
                    break;
                case '}':
                    if (S.empty() || S.top() != '{') return false;
                    S.pop();
                    break;
            }
        }
        return S.empty();
    }
};
