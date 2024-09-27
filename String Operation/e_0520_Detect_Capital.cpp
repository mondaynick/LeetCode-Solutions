/*
  給定一字串，若符合以下三種規則，則回傳true，否則回傳false
  (1) 首字母大寫，其餘全部小寫
  (2) 全部字母皆為大寫
  (3) 全部字母皆為小寫

  若字串只有一個字母，其結果必為true，否則分為以下兩種情況：
    (1) 若第一個字母為大寫，分為以下兩種情況：
      (1) 若第二個字母為大寫，則其餘字母必須為大寫
      (2) 若第二個字母為小寫，則其餘字母必須為小寫
    (2) 若第一個字母為小寫，則其餘字母必須要為小寫
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() == 1) return true;
        if (isupper(word[0])) {
            if (isupper(word[1])) {
                for (int i = 2 ; i < word.length() ; i++) {
                    if (islower(word[i])) return false;
                }
            } else {
                for (int i = 2 ; i < word.length() ; i++) {
                    if (isupper(word[i])) return false;
                }
            }
        } else {
            for (int i = 1 ; i < word.length() ; i++) {
                if (isupper(word[i])) return false;
            }
        }
        return true;
    }
};
