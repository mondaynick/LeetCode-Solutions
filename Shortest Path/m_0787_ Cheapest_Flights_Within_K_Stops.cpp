/*
  有n個城市中間由航班連接，給定一組資料flights，其中flights[i] = [from, to, price]，分別代表該航班的起點、
  終點和價格，另外給出一個出發城市src和目的地城市dst，請找出一條航線最多經過k次轉機，且該航線是所有可行航線中價格
  最便宜的，如果存在那麼一條航線就回傳該航線的價格，否則回傳-1

  只能經過k次的轉機，又k次的轉機代表所求的路徑最多經過k + 1條邊，因此Ballman-Ford最多進行k + 1次relaxation
 */

class Solution {
private:
    struct Edge {
        int from;
        int to;
        int cost;
    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<Edge> edges;
        for (vector<int> ite: flights) edges.push_back({ite[0], ite[1], ite[2]});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0 ; i <= k ; i++) {
            vector<int> temp(dist);
            for (Edge edge: edges) {
                if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.cost < temp[edge.to]) {
                    temp[edge.to] = dist[edge.from] + edge.cost;
                }
            }
            dist = temp;
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
