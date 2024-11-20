/*
  給定一無向圖有n個節點，編號從0開始，另外給一陣列edges紀錄邊，其中edges[i] = [a, b]，
  代表a、b間的成功機率，且其成功機率為succProb[i]，請計算出從start節點到end節點的最大成
  功機率，要是中間沒有任何路徑請回傳0

  利用Dijkstra's Algorithm，只是題目轉成求最大路徑
 */

struct Vertex {
    int index;
    double dist;
};

class cmp {
public:
    bool operator()(Vertex v1, Vertex v2) {
        return v1.dist < v2.dist;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<Vertex>> adjList(n);
        for (int i = 0 ; i < edges.size() ; i++) {
            adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        unordered_set<int> visited;
        priority_queue<Vertex, vector<Vertex>, cmp> pq;
        vector<double> dist(n, 0);

        // initialize source
        dist[start_node] = 1;
        pq.push({start_node, 1});

        // relaxation
        while (!pq.empty()) {
            Vertex curr = pq.top();
            pq.pop();
            if (!visited.count(curr.index)) {
                visited.insert(curr.index);
                for (Vertex vertex: adjList[curr.index]) {
                    if (dist[curr.index] * vertex.dist > dist[vertex.index]) {
                        dist[vertex.index] = dist[curr.index] * vertex.dist;
                        pq.push({vertex.index, dist[vertex.index]});
                    }
                }
                if (curr.index == end_node) return dist[end_node];
            }
        }

        return 0;
    }
};
