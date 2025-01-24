/*
  給定一個矩陣 graph ，其中 graph[i] 代表頂點 i 指向哪些頂點，
  找出哪些頂點為 safe node ，並回傳遞增排序後的陣列
  若一個頂點為 safe node ，則對該頂點做 dfs 不會再遇到自己

  (1) 先紀錄那些 outdegree 為 0 的節點放至 queue 中
  (2) 每次從 queue 中拿出那些 outdegree 為 0 的頂點加入 res
  (3) 將其他指向該頂點的邊刪掉，也就是將那些頂點的 outdegree 都減 1
  (4) 若有頂點的 outdegree 減 1 後等於 0 ，則也將該頂點加入 queue 中
  (5) 直到 queue 為空，將 res 遞增排序後回傳
 */

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int len = graph.size();
        queue<int> q;
        vector<int> outdegree(len, 0);
        vector<set<int>> neighbor(len);
        for (int i = 0 ; i < len ; i++) {
            for (int ite: graph[i]) {
                outdegree[i]++;
                neighbor[ite].insert(i);
            }
        }
        for (int i = 0 ; i < len ; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            for (int ite: neighbor[temp]) {
                outdegree[ite]--;
                if (outdegree[ite] == 0)
                    q.push(ite);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
