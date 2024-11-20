/*
  網路中有n個節點，編號從1到n，另外itmes代表網路中節點和節點之間的訊號延遲時間，其中times[i] = [s, t, w]，
  s代表訊號起點，t代表訊號終點，w代表訊號的延遲時間，請問從節點k發出訊號之後，直到網路中所有節點都收到訊號至少需
  要多少時間，若無法讓全部網路節點都收到訊號則回傳-1
  
  利用SPFA演算法
 */

class Solution {
private:
    struct Edge {
        int to;
        int cost;
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>> adjList(n);
        queue<int> Q;
        vector<int> dist(n, INT_MAX);
        vector<bool> inque(n, false);
        Q.push(k - 1);
        dist[k - 1] = 0;
        inque[k - 1] = true;
        for (vector<int> ite: times) {
            adjList[ite[0] - 1].push_back({ite[1] - 1, ite[2]});
        }
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            inque[curr] = false;
            for (Edge edge: adjList[curr]) {
                if (dist[curr] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = dist[curr] + edge.cost;
                    if (!inque[edge.to]) {
                        inque[edge.to] = true;
                        Q.push(edge.to);
                    }
                }
            }
        }
        int res = INT_MIN;
        for (int ite: dist) {
            if (ite > res) res = ite;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};
