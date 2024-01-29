/*
  輸入一字串，輸出將字串翻轉成單調遞增的最小翻轉數(0可以翻轉成1、1可以翻轉成0)

  翻轉後的字串共有兩種情況:
    case 1-1: 全部都是0 (e.g. 00000000)
    case 1-2: 前面0，接下來後面都是1 (e.g. 00011111)
  因此在第i位時要變成單調遞增共有四種情況，令f1為case 1-1所翻轉的次數、f2為case 1-2所翻轉的次數:
    case 2-1: s[i] == 0 && case 1-1 => 不需做任何改變
    case 2-2: s[i] == 0 && case 1-2 => f2++
    case 2-3: s[i] == 1 && case 1-1 => f1++
    case 2-4: s[i] == 1 && case 1-2 => 第i - 1位選擇case 1-1或case 1-2都可以
  遍歷字串，選出f1、f2較小者
 */

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int f1 = 0, f2 = 0;
        for (auto iter: s) {
            if (iter == '0') {
                f2++;
            } else {
                f2 = min(f2, f1);
                f1++;
            }
        }
        return min(f1, f2);
    }
};
