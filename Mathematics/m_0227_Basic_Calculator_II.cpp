/*
  給定中序運算式，回傳其結果

  定義number為目前尋訪的運算元 sign為目前尋訪的運算元
 */

class Solution {
public:
    int calculate(string s) {
        int len = s.length(), num = 0;
        char sign = '+';
        stack<int> stk;
        for (int i = 0 ; i < len ; i++) {
            char c = s[i];
            if (c == ' ') continue;
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!isdigit(c)) {
                switch(sign) {
                    int prev;
                    case '+':
                        stk.push(num);
                        break;
                    case '-':
                        stk.push(-num);
                        break;
                    case '*':
                        prev = stk.top();
                        stk.pop();
                        stk.push(prev * num);
                        break;
                    case '/':
                        prev = stk.top();
                        stk.pop();
                        stk.push(prev / num);
                        break;
                }
                sign = c;
                num = 0;
            }
        }
        switch(sign) {
            int prev;
            case '+':
                stk.push(num);
                break;
            case '-':
                stk.push(-num);
                break;
            case '*':
                prev = stk.top();
                stk.pop();
                stk.push(prev * num);
                break;
            case '/':
                prev = stk.top();
                stk.pop();
                stk.push(prev / num);
                break;
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
