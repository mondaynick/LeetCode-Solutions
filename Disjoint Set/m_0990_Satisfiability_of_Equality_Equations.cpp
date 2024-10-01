/*
  給定一個陣列equations，裝著若干由字串表示的算式，每個equations[i]的長度都是4，而且
  只有兩種情況，"a==b"或者"a!=b"，其中a、b可以是任意小寫字母，求equations中所有算式
  是否邏輯合法(即邏輯不互相衝突，如："a==b", "a==c", "b!=c"即為不合法)

  先處理"=="，將等號兩邊的字母union，在處理"!="，若兩邊find後是同個結果代表邏輯不合法
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
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet dj(26);
        for (string eqs: equations) {
            if (eqs[1] == '=') {
                cout << eqs[0] - 'a' << " " << eqs[3] - 'a' << endl;
                dj.Union(eqs[0] - 'a', eqs[3] - 'a');
            }
        }
        for (string eqs: equations) {
            if (eqs[1] == '!') {
                if (dj.isConnect(eqs[0] - 'a', eqs[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};
