/*
  給第一個board陣列，類似圍棋的規則，若"O"四面八方皆被"X"圍住，則將"O"換成"X"

  很明顯，邊角的"O"一定不會被"X"所包圍住，利用disjoint set，創造一個虛擬節點，
  將邊角的"O"與dummy連接，再將與邊角"O"連通的"O"以連接在一起，最後不與dummy連接的"O"即可變成"X"
 */

class DisjointSet {
private:
    int size;
    int* parent = nullptr;
    int* rank = nullptr;
    int Find(int p) {
        if (parent[p] != p) {
            parent[p] = Find(parent[p]);
            return parent[p];
        } else {
            return p;
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
    bool Connected(int p, int q) {
        return Find(p) == Find(q);
    }
    int getSize() {
        return size;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        DisjointSet dj(rows * cols + 1);
        int dummy = rows * cols;
        for (int i = 0 ; i < rows ; i++) {
            if (board[i][0] == 'O') {
                dj.Union(dummy, cols * i);
            }
            if (board[i][cols - 1] == 'O') {
                dj.Union(dummy, cols * i + (cols - 1));
            }
        }
        for (int j = 0 ; j < cols ; j++) {
            if (board[0][j] == 'O') {
                dj.Union(dummy, j);
            }
            if (board[rows - 1][j] == 'O') {
                dj.Union(dummy, cols * (rows - 1) + j);
            }
        }
        for (int i = 1 ; i < rows - 1 ; i++) {
            for (int j = 1 ; j < cols - 1 ; j++) {
                if (board[i][j] == 'O') {
                    if (board[i - 1][j] == 'O')
                        dj.Union(i * cols + j, (i - 1) * cols + j);
                    if (board[i + 1][j] == 'O')
                        dj.Union(i * cols + j, (i + 1) * cols + j);
                    if (board[i][j - 1] == 'O')
                        dj.Union(i * cols + j, i * cols + (j - 1));
                    if (board[i][j + 1] == 'O')
                        dj.Union(i * cols + j, i * cols + (j + 1));
                }
            }
        }
        for (int i = 1 ; i < rows - 1 ; i++) {
            for (int j = 1 ; j < cols - 1 ; j++) {
                if (!dj.Connected(dummy, i * cols + j))
                    board[i][j] = 'X';
            }
        }
    }
};
