/*
  給定一個圖 判斷該圖是否為雙分圖

  利用bfs，假設s為拜訪的起點
  enqueue(s)
  while queue is not empty
    u = dequeue()
    for v in adj(u)
      if v is colored
        chech color[u] == color[v] if true return false
      else
        color vertex v into opposite
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0); // 0: none, 1: red, -1: blue
        unordered_set<int> memo;
        for (int i = 0 ; i < graph.size() ; i++) {
            if (memo.count(i)) continue;
            queue<int> Q;
            Q.push(i);
            while (!Q.empty()) {
                int currNode = Q.front();
                int currColor = color[currNode];
                memo.insert(currNode);
                Q.pop();
                for (int neighbor: graph[currNode]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = (currColor == 1) ? -1 : 1;
                        Q.push(neighbor);
                    } else {
                        if (currColor == color[neighbor]) return false;
                    }
                }
            }
        }
        return true;
    }
};
