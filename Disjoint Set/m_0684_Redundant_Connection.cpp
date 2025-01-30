/*
  給定一個長度為 n x 2 的矩陣 edges ，代表圖中共有 n 個頂點被標示為編號 1 到 n ，
  edges[i] = [ai, bi] 代表在圖中頂點 ai 和 頂點 bi 之中加入一條邊，
  若加入的這條邊會使得該圖出現 cycle ，則回傳該邊 [ai, bi]

  利用disjoint set
 */

class DisjointSet {
private:
    int *rank = nullptr;
    int *parent = nullptr;
public:
    DisjointSet (int n) {
        rank = new int[n];
        parent = new int[n];
        for (int i = 0 ; i < n ; i++) {
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int Find(int x) {
        if (parent[x] != x) {
            return parent[x] = Find(parent[x]);
        } else {
            return parent[x];
        }
    }

    void Union(int x, int y) {
        int rootX = Find(x), rootY = Find(y);
        if (rootX == rootY) return;
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            rank[rootY] += rank[rootX];
        } else {
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
    }

    bool Connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        DisjointSet dj(len + 1);
        for (int i = 0 ; i < len ; i++) {
            if (dj.Connected(edges[i][0], edges[i][1])) {
                return {edges[i][0], edges[i][1]};
            } else {
                dj.Union(edges[i][0], edges[i][1]);
            }
        }
        return {};
    }
};
