/*
  給定n個頂點的座標，points[i] = [xi, yi]代表第i個頂點的x座標為xi且y座標為yi，
  回傳將所有頂點連成生成樹的最小成本，兩頂點的成本定義為|x1 - x2| + |y1 - y2|

  利用Kruskal's algorithm
 */

struct Edge {
    int from;
    int to;
    int cost;
};

class DisjointSet {
private:
    int size = 0;
    int *parent = nullptr;
    int *rank = nullptr;
public:
    DisjointSet(int n) {
        size = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0 ; i < n ; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int Find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            return parent[x] = Find(parent[x]);
        }
    }
    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX == rootY) return;
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            rank[rootY] += rank[rootX];
        } else {
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
        size--;
    }
    int Size() {
        return size;
    }
};

class Solution {
private:
    struct cmp {
        bool operator()(Edge e1, Edge e2) {
            return e2.cost < e1.cost;
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<Edge, vector<Edge>, cmp> pq;
        DisjointSet dj(points.size());
        for (int i = 0 ; i < points.size() - 1 ; i++) {
            for (int j = i + 1 ; j < points.size() ; j++) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({i, j, cost});
            }
        }
        int res = 0;
        while (dj.Size() != 1) {
            Edge temp = pq.top();
            pq.pop();
            if (dj.Find(temp.from) != dj.Find(temp.to)) {
                dj.Union(temp.from, temp.to);
                res += temp.cost;
            }
        }
        return res;
    }
};
