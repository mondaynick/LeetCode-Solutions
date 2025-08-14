/*
  給定一個字串 nums ，該字串可能有多個子字串其長度為 3 且該字串的所有字元皆相同，
    (1) 若無存在子字串，回傳空字串
    (2) 若存在一個子字串，回傳該字串
    (3) 若存在多個字串，回傳其轉成整數之最大者，如: "777"大於"333"，回傳"777"

  遍歷一次即得結果
 */

class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        int len = num.length(), dup = 0;
        char curr = '.';
        for (int i = 0; i < len; ++i) {
            if (num[i] == curr) {
                ++dup;
                if (dup == 3) {
                    if (res == "") {
                        res = string(3, num[i]);
                    } else {
                        if (curr > res[0]) res = string(3, num[i]);
                    }
                }
            } else {
                curr = num[i];
                dup = 1;
            }
        }
        return res;
    }
};
