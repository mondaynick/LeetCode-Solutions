/*
  給定一滑動拼圖，回傳其變成"123450"所需的最少步驟，若無法達成則回傳-1

  利用BFS
 */

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string temp = "";
        for (int i = 0 ; i < 2 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                temp += board[i][j] + '0';
            }
        }
        queue<string> q;
        q.push(temp);
        unordered_set<string> memo;
        int count = 0;
        while (!q.empty()) {
            for (int i = q.size() ; i > 0 ; i--) {
                string curr = q.front();
                q.pop();
                memo.insert(curr);
                if (curr == "123450") return count;
                int idx = curr.find("0");

                if (idx >= 3) { // up
                    swap(curr[idx], curr[idx - 3]);
                    if (!memo.count(curr)) q.push(curr);
                    swap(curr[idx], curr[idx - 3]);
                }

                if (idx <= 2) { // down
                    swap(curr[idx], curr[idx + 3]);
                    if (!memo.count(curr)) q.push(curr);
                    swap(curr[idx], curr[idx + 3]);
                }

                if (idx % 3 != 0) { // left
                    swap(curr[idx], curr[idx - 1]);
                    if (!memo.count(curr)) q.push(curr);
                    swap(curr[idx], curr[idx - 1]);
                }

                if (idx % 3 != 2) { // right
                    swap(curr[idx], curr[idx + 1]);
                    if (!memo.count(curr)) q.push(curr);
                    swap(curr[idx], curr[idx + 1]);
                }
            }
            count++;
        }
        return -1;
    }
};
