/*
  平衡字串是指字串當中'L'和'R'出現次數相同者，給定一個平衡字串s，把它分割為若干個
  平衡子字串，使得切割出來的子字串個數最多，回傳該切割出的個數

  初始left, right, count設為0，遍歷字串
    當遍歷到'L'時left++
    當遍歷到'R'時right++
    若left等於right時count++並將left和right設為0
 */

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int left = 0;
        int right = 0;
        for (char ite: s) {
            if (ite == 'L') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                count++;
                left = right = 0;
            }
        }
        return count;
    }
};
