/*
  給定字串num和整數k，回傳從字串中刪除k個字元後所得之最大值為何

  每次遍歷字串，忽略單調遞增，遇到第一個遞減時，扣掉上一個字元
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() <= k) return "0";

        stack<char> S;
        for (int i = 0 ; i < num.length() ; i++) {
            char temp = num[i];
            while (!S.empty() && k > 0 && S.top() > temp) {
                S.pop();
                k--;
            }
            S.push(temp);
        }

        while (k > 0) {
            S.pop();
            k--;
        }

        string res;
        while (!S.empty()) {
            res += S.top();
            S.pop();
        } 
        reverse(res.begin(), res.end());

        int i;
        for (i = 0 ; i < res.length() ; i++) {
            if (res[i] != '0') {
                break;
            }
        }
        return (i == res.length()) ? "0" : res.substr(i);
    }
};
