/*
  給定中序運算式，回傳其結果

  定義number為目前尋訪的運算元 sign為目前尋訪的運算元
  括弧可以利用遞迴 遞迴時 idx會指向左括弧 而i會指向對應的右括弧
 */

class Solution {
public:
    int calculate(string s) {
        int num = 0, len = s.length(), prev;
        stack<int> stk;
        char sign = '+';
        for (int i = 0 ; i < len ; i++) {
            char c = s[i];
            if (c == ' ') continue;
            if (c == '(') {
                int idx = i, count = 0;
                for (; i < len ; i++) {
                    if (s[i] == '(') count++;
                    if (s[i] == ')') count--;
                    if (count == 0) break;
                }
                num = calculate(s.substr(idx + 1, i - idx - 1));
            } else if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                switch(sign) {
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
