/*
  給定 edges ，其中 edges[i][0] = a 和 edges[i][1] = b 分別代表頂點 a 和 b 之間有建立一條邊，且 amount[i] 若為
  負數則代表開啟頂點 i 的大門需付多少的成本，反之則為獎勵金，給定 bob 代表 Bob 從頂點 bob 出發，而 Alice 從頂點 0 出
  發， Bob 會往頂點 0 走去，當兩人同時遇上大門且該大門尚未被打開時，則兩人需同時平均地付出成本或獲得獎勵金，反之則先到的
  先付出或獲得，若 Alice 欲走向任何一個葉節點，則所得到的最大獎勵金為何

  先遍歷 Bob ，再遍歷 Alice
 */

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        vector<int> ts(n, n);
        function<bool(int i, int fa, int t)> dfs1 = [&](int i, int fa, int t) -> bool {
            if (i == 0) {
                ts[i] = t;
                return true;
            }
            for (int j : gamount[i]) {
                if (j != fa && dfs1(j, i, t + 1)) {
                    ts[j] = t + 1;
                    return true;
                }
            }
            return false;
        };
        dfs1(bob, -1, 0);
        ts[bob] = 0;
        int ans = INT_MIN;
        function<void(int i, int fa, int t, int v)> dfs2 = [&](int i, int fa, int t, int v) {
            if (t == ts[i])
                v += amount[i] >> 1;
            else if (t < ts[i])
                v += amount[i];
            if (g[i].size() == 1 && g[i][0] == fa) {
                ans = max(ans, v);
                return;
            }
            for (int j : g[i])
                if (j != fa) dfs2(j, i, t + 1, v);
        };
        dfs2(0, -1, 0, 0);
        return ans;
    }
};
