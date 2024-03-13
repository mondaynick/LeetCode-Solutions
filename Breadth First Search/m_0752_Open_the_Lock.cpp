/*
  給定deadends和target，剛開始行李箱為0000，求轉到target且不能出現deadends中的數字所需最小轉動數

  利用BFS
 */

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;

        queue<string> q;
        q.push("0000");

        string curr, prev, next;
        for (int size = 1, level = 1 ; !q.empty() ; size = q.size(), level++) {
            while (size--) {
                curr = prev = next = q.front(); q.pop();
                for (int i = 0 ; i < 4 ; i++) {
                    next[i] += (next[i] == '9' ? -9 : 1);
                    if (next == target) return level;
                    if (!visited.count(next)) q.push(next), visited.insert(next);

                    prev[i] -= (prev[i] == '0' ? -9 : 1);
                    if (prev == target) return level;
                    if (!visited.count(prev)) q.push(prev), visited.insert(prev);

                    prev = next = curr;
                }
            }
        }

        return -1;
    }
};
