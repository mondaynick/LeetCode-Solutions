/*
  給定一個字元陣列tasks代表CPU需要完成的所有任務，不同的字元代表不同類型
  的任務，這些任務可以被任意順序完成，每個任務需要一個單位時間來完成，而在
  任一個單位時間內，CPU可以完成某一個工作或者什麼都不做，考慮一個非負整數
  n，代表兩個相同種類的任務間最少要間隔多久才能進行，回傳CPU完成所有給定
  任務最少需要花費的總時間

  如果有工作為AAAAABBBBBCCC，其間隔時間為4，則安排如下
  ABC--ABC--ABC--AB---AB---AB
  如果有工作為AAABBBCCCDDDEEEFFF，其間隔時間為2，則安排如下
  ABCDEFABCDEFABCDEF
  -
  因此考慮len表示tasks的大小，maxFreq表示所有任務出現次數最大值，maxKind
  表示有幾項任務的出現次數等於maxFreq，則有兩種可能
  有空閒時：(n + 1)(maxFreq - 1) + maxKind
  沒空閒時：len
  因此只要取兩者之間最大值
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> memo;
        int maxFreq = 1;
        int maxKind = 0;
        for (char c: tasks) {
            if (memo.count(c)) {
                int temp = ++memo[c];
                if (temp > maxFreq) maxFreq = temp;
            } else {
                memo[c] = 1;
            }
        }
        for (pair<int, int> ite: memo) {
            if (ite.second == maxFreq) maxKind++;
        }
        int len = tasks.size();
        int res = (n + 1) * (maxFreq - 1) + maxKind;
        return max(len, res);
    }
};
