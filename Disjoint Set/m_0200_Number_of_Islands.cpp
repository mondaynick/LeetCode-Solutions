/*
  給定一張圖，求島嶼數量，其中1為陸地、0為海洋

  利用disjoint set
 */

class DisjointSet {
private:
    int size = 0;
    int *parent = nullptr;
    int *rank = nullptr;
    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
            return parent[x];
        } else {
            return x;
        }
    }
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
    void Union(int p, int q) {
        int rootP = Find(p);
        int rootQ = Find(q);
        if (rootP == rootQ) return;
        if (rank[rootP] < rank[rootQ]) {
            parent[rootP] = rootQ;
            rank[rootQ] += rank[rootP];
        } else {
            parent[rootQ] = rootP;
            rank[rootP] += rank[rootQ];
        }
        size--;
    }
    bool isConnect(int p, int q) {
        return Find(p) == Find(q);
    }
    int getSize() {
        return size;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int dummy = rows * cols;
        DisjointSet dj(dummy + 1);
        for (int i = 0 ; i < rows ; i++) {
            for (int j = 0 ; j < cols ; j++) {
                int idx = i * cols + j;
                if (grid[i][j] == '0') {
                    dj.Union(dummy, idx);
                } else {
                    if (j != 0 && grid[i][j - 1] == '1') {
                        dj.Union(idx, idx - 1);
                    }
                    if (i != 0 && grid[i - 1][j] == '1') {
                        dj.Union(idx, idx - cols);
                    }
                }
            }
        }
        return dj.getSize() - 1;
    }
};
