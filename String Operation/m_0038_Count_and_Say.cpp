/*
  給定一整數n回傳countAndSay(n)，countAndSay其定義如下：
    countAndSay(1) = "1"
    countAndSay(n) = countAndSay(n - 1)的遊程編碼

  遊程編碼將連續的數字轉換成該數字連續出現的次數加上該數字為何，例如：
    "33"會變成"23"
    "5"會變成"15"
    "3322251"會變成"23321511"
 */

class Solution {
public:
    string handler(int n, string key) {
        if (n == 1) {
            return key;
        } else {
            char c = ' ';
            int count = 0;
            string res = "";
            for (int i = 0 ; i < key.length() ; i++) {
                if (key[i] == c) {
                    count++;
                } else {
                    if (c != ' ') {
                        res += to_string(count) + c;
                    }
                    c = key[i];
                    count = 1;
                }
            }
            res += to_string(count) + c;
            return handler(n - 1, res);
        }
    }

    string countAndSay(int n) {
        return handler(n, "1");
    }
};
