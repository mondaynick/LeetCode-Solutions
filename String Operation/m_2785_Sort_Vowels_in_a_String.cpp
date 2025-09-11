/*
  給定一個字串 s ，回傳一個字串滿足以下條件：
    (1) 該字串的所有子音位置要和 s 相同
    (2) 該字串的所有母音需照 ASCII排序

  先遍歷字串將所有母音拉出來做排序，再遍歷字串將所有母音重新填入
 */

class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowels;
        for (int i = 0; i < s.length(); ++i) {
            int c = s[i];
            if (isVowel(c)) vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        int idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            int c = s[i];
            if (isVowel(c)) s[i] = vowels[idx++];
        }
        return s;
    }

private:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};
