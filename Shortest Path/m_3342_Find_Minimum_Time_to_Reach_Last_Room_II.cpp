/*
  有一個地牢，其中有 n x m 個房間排成網格狀，給定一個 n x m 的二維陣列 moveTime ，
  其中 moveTime[i][j] 代表從起點 (0, 0) 開始，你可以移動到該房間的最小時間，假設你
  從起點 (0, 0) 且時間 t = 0 開始，房間和房間之間的移動一次需花費 1 秒，下一次需花費
  2 秒，並且 1 秒和 2 秒交互進行，你可以按照上、下、左、右去遍歷各個房間，回傳到終點
  (n - 1, m - 1) 的最小時間為何

  此為一個 min-max problem ，利用 Dijkstra's algorithm ：
    定義 distance[i][j] 為從起點 (0, 0) 到 (i, j) 所需的最小時間，
    起初 distance[0][0] 先設定為 0 ，並將其他 distance[i][j] 設為無限大，
    利用 priority queue 每次取得最小距離的房間進行鬆弛操作：
      (1) 若此房間為終點，返回其紀錄的時間
      (2) 否則，更新到此相鄰房間的最小時間
    即可得到從起點 (0, 0) 到終點 (n - 1, m - 1) 的最小時間
 */

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rowlen = moveTime.size();
        int collen = moveTime[0].size();
        vector<vector<int>> distance(rowlen, vector<int>(collen, INT_MAX));
        distance[0][0] = 0;
        unordered_set<string> visited;
        priority_queue<array<int, 4>, vector<array<int, 4>>, decltype([](auto &lhs, auto &rhs) {
            return lhs[0] > rhs[0];
        })> pq;
        pq.push({0, 2, 0, 0});
        visited.insert("0,0");
        array<int, 5> direction = {-1, 0, 1, 0, -1};
        while (true) {
            auto [t, dt, row, col] = pq.top();
            pq.pop();
            if (row == rowlen - 1 && col == collen - 1) {
                return t;
            }
            for (int i = 0 ; i < 4 ; ++i) {
                int drow = row + direction[i];
                int dcol = col + direction[i + 1];
                string key = to_string(drow) + "," + to_string(dcol);
                if (drow >= 0 && drow < rowlen && dcol >= 0 && dcol < collen) {
                    if (visited.count(key)) continue;
                    int time = max(moveTime[drow][dcol], distance[row][col]) + (3 - dt);
                    if (time < distance[drow][dcol]) {
                        distance[drow][dcol] = time;
                        pq.push({time, 3 - dt, drow, dcol});
                        visited.insert(key);
                    }
                }
            }
        }
    }
};
