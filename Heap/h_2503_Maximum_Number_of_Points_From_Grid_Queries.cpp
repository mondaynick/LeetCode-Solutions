/*
  給定一個矩陣 grid[m][n] 和一個陣列 queries[q] ， 回傳的答案為陣列 res[q] ，其中 res[i] 滿足以下：
    從grid[0][0] 開始，若當前 grid[i][j] 的值有小於 queries[i] 則可以往上下左右四邊走，
    res[i] 等於有多少個元素小於 queries[i]

  先對 queries 做排序，利用 priority queue 和 bfs 探訪有多少的值小於當前的 query
*/

struct Query {
    int index;
    int value;
    int res;
};

struct Node {
    int row;
    int col;
    int value;
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int len = queries.size();
        vector<Query> qs(len);
        for (int i = 0 ; i < len ; ++i) {
            qs[i] = {
                .index = i,
                .value = queries[i],
                .res = 0
            };
        }
        sort(qs.begin(), qs.end(), [](const Query &lhs, const Query &rhs) {
            return lhs.value < rhs.value;
        });
        int q = 0;
        unordered_set<string> visited;
        priority_queue<Node, vector<Node>, decltype([](const Node &lhs, const Node &rhs) {
            return lhs.value > rhs.value;
        })> pq;
        int res = 0;
        pq.push({
            .row = 0,
            .col = 0,
            .value = grid[0][0]
        });
        visited.insert("0,0");
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (q < len) {
            int pivot = qs[q].value;
            while (!pq.empty() && pq.top().value < pivot) {
                ++res;
                auto temp = pq.top();
                pq.pop();
                for (int i = 0 ; i < 4 ; ++i) {
                    int newRow = temp.row + direction[i][0];
                    int newCol = temp.col + direction[i][1];
                    if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()) continue;
                    string key = to_string(newRow) + "," + to_string(newCol);
                    if (visited.count(key)) continue;
                    visited.insert(key);
                    pq.push({
                        .row = newRow,
                        .col = newCol,
                        .value = grid[newRow][newCol]
                    });
                }
            }
            qs[q].res = res;
            ++q;
        }
        vector<int> ans(len);
        for (int i = 0 ; i < len ; ++i) {
            ans[qs[i].index] = qs[i].res;
        }
        return ans;
    }
};
