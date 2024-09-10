/*
  給定中序運算式，回傳其結果

  定義number為目前尋訪的運算元 sign為目前尋訪的運算元為正數或負數 res為目前累計的答案
 */

class Solution {
public:
    int calculate(string s) {
        int number = 0;
        int sign = 1;
        int res = 0;
        stack<int> S;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                number = number * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                res += sign * number;
                number = 0;
                sign = (s[i] == '-') ? -1 : 1; 
            } else if (s[i] == '(') {
                S.push(sign);
                S.push(res);
                sign = 1;
                res = 0;
            } else if (s[i] == ')') {
                res += sign * number;
                number = 0;
                int prevResult = S.top(); S.pop();
                int prevSign = S.top(); S.pop();
                res = res * prevSign + prevResult;
            }
        }
        if (number != 0) res += sign * number;
        return res;
    }
};
