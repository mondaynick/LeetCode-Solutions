/*
  圖上有n個城市，城市的編號為0到n - 1，另外給一個edges陣列，其中edges[i] = [from, to, weight]，
  分別代表from城市與to城市間的最短距離為weight
  若給定一整數distanceThreshold，定義若兩城市的最短距離小於等於distanceThreshold，則代表兩個城市
  互為鄰居，求含有最少鄰居的城市，若含有多個則回傳編號最大者

  利用Floyd Warshall algorithm求出任兩點之間的最短路徑，再找出誰含有最小鄰居個數
 */

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0 ; i < n ; i++) dist[i][i] = 0;
        for (vector<int> edge: edges) {
            dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0 ; k < n ; k++) {
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int res = INT_MIN, temp = INT_MAX;
        for (int i = 0 ; i < n ; i++) {
            int count = 0;
            for (int j = 0 ; j < n ; j++) {
                if (dist[i][j] <= distanceThreshold) count++;
            }
            if (count <= temp && i > res) {
                res = i;
                temp = count;
            }
        }
        return res;
    }
};
