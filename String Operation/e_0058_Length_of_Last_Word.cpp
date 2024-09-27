/*
  給定一字串，回傳其最後一個單字的長度

  利用single pointer，注意可能會出現最後一個單字後有空白的情況，如："hello world  "
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for (int i = s.length() - 1 ; i >= 0 ; i--) {
            if (s[i] == ' ') {
                continue;
            } else {
                do {
                    count++;
                    i--;
                } while (i >= 0 && s[i] != ' ');
                return count;
            }
        }
        return 0;
    }
};
