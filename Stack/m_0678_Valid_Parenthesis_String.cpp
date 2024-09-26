/*
  給定一字串，該字串只包括"(", ")", "*"三個字元，"*"可當作"(", ")", " "，
  每一個左括弧一定要配對一個往後其對應的右括弧才算合法，求該字串是否合法

  利用堆疊，遇到"(", "*"時紀錄該字元的索引，遇到右括弧則先pop left再pop star
  為了避免出現"*("的情況，需要確保"*"必在"("後面
 */

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if (left.empty() && star.empty()) return false;
                if (!left.empty()) left.pop();
                else star.pop();
            }
        }
        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};
