/*
  給定deadends和target，剛開始行李箱為0000，求轉到target且不能出現deadends中的數字所需最小轉動數

  利用BFS
 */

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> visited (deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        int step = 0;
        while (!q.empty()) {
            step++;
            for (int i = q.size() ; i > 0 ; i--) {
                string temp = q.front();
                q.pop();
                for (int j = 0 ; j < 4 ; j++) {
                    string prev = temp;
                    prev[j] -= (prev[j] == '0') ? -9 : 1;
                    if (prev == target) return step;
                    if (!visited.count(prev)) {
                        q.push(prev);
                        visited.insert(prev);
                    }

                    string next = temp;
                    next[j] += (next[j] == '9') ? -9 : 1;
                    if (next == target) return step;
                    if (!visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};
