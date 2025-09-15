/*
  給定兩個字串 text 和 brokenLetters ，其中 brokenLetters 代表鍵盤上的哪些字母是壞掉的，
  而 text 包含許多個英文單字，彼此用空格隔開，在鍵盤有些字母壞掉的狀況下，你可以打出多少完整的
  單字

  先記錄有哪些字母壞掉，然後再遍歷字串
 */

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for (char brokenLetter : brokenLetters) {
            broken.insert(brokenLetter);
        }
        int res = 0, len = text.length();
        bool isComplete = true;
        for (int i = 0; i < len; ++i) {
            char currentLetter = text[i];
            if (currentLetter == ' ') {
                if (isComplete) ++res;
                isComplete = true;
            }
            if (!isComplete) continue;
            else if (broken.count(currentLetter)) isComplete = false;
        }
        if (isComplete) ++res;
        return res;
    }
};
