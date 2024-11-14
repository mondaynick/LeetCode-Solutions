/*
  給定圖的頂點數量n，和一個陣列edges，其中edges[i] = [i, j, w]代表
  頂點i和頂點j建立一條邊且其weight為w，該圖可能有多種最小生成樹，若一條
  邊在所有最小生成樹皆出現則該邊稱為critial edge，若一條邊至少會在一個
  最小生成樹中出現，則該邊為pseudo-critical edge，回傳critical edge
  和pseudo-critical edge分別為哪些邊

  利用Kruskal's algorithm去求minimum spanning tree，
  (1) 若一條邊為critical edge，則將該邊刪除後，不一定可以建出minimum
      spanning tree又或者建出的minimum spanning tree其cost比原來還大
  (2) 若一條邊為pseudo-critical edge，則將該邊刪除後，建出的minimum
      spanning tree其cost和原來相同
  (3) 若一條邊沒滿足以上條件，則不為critical也不為pseudo-critial edge
  */

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
            return parent[x];
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

int MST(int vertex, vector<vector<int>> edges, int ex, int in) {
    DisjointSet dj(vertex);
    int res = 0;
    int edge = 0;
    if (in >= 0) {
        for (vector<int> ite: edges) {
            if (ite[3] == in) {
                dj.Union(ite[0], ite[1]);
                edge++;
                res += ite[2];
            }
        }
    }
    for (int i = 0 ; i < edges.size() ; i++) {
        if (edges[i][3] == ex) continue;
        if (dj.Find(edges[i][0]) != dj.Find(edges[i][1])) {
            dj.Union(edges[i][0], edges[i][1]);
            edge++;
            res += edges[i][2];
        }
    }
    return (edge == vertex - 1) ? res : INT_MAX;
}

class Solution {
private:
    static bool cmp(vector<int> a, vector<int> b) {
        if (a[2] != b[2]) return a[2] < b[2];
        return a < b;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0 ; i < edges.size() ; i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), cmp);
        int minCost = MST(n, edges, -1, -1);
        vector<int> critical, pseudo;
        for (int i = 0 ; i < edges.size() ; i++) {
            if (MST(n, edges, i, -1) > minCost) {
                critical.push_back(i);
            } else if (MST(n, edges, -1, i) == minCost) {
                pseudo.push_back(i);
            }
        }
        return {critical, pseudo};
    }
};
