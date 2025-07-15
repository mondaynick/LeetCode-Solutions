/*
  給定一個字串 word ，回傳該字串是否合法，若一個字串為合法則需滿足以下所有條件：
    (1) 字串長度至少為 3
    (2) 字串只能包含數字、小寫英文字母和大寫英文字母
    (3) 至少包含一個英文子音
    (4) 至少包含一個英文母音

  根據給定條件遍歷 word
 */ 

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        int vowelCount = 0, consonantCount = 0;
        for (char w: word) {
            if ((w >= '0') && (w <= '9')) {
                continue;
            } else if ((w >= 'a') && (w <= 'z')) {
                if (w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u') {
                    ++consonantCount;
                } else {
                    ++vowelCount;
                }
            } else if ((w >= 'A') && (w <= 'Z')) {
                if (w == 'A' || w == 'E' || w == 'I' || w == 'O' || w == 'U') {
                    ++consonantCount;
                } else {
                    ++vowelCount;
                }
            } else {
                return false;
            }
        }
        return (vowelCount > 0) && (consonantCount > 0);
    }
};
