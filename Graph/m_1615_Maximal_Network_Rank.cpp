/*
  共有n個城市，且有一些道路連接其間，每個roads[i] = [a,b]代表了城市a和城市b之間的一條雙向道路，
  兩個不同城市間的network rank被定義為連接到這兩個城市間的道路數量總數，若有一條路連接的正好是這
  兩個城市，則只能被計算一次，回傳這些城市中，任意兩個城市最大的network rank
 */

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> neighbor(n);
        for (vector<int> ite: roads) {
            neighbor[ite[0]].insert(ite[1]);
            neighbor[ite[1]].insert(ite[0]);
        }
        int res = INT_MIN;
        for (int i = 0 ; i < n ; i++) {
            for (int j = i + 1 ; j < n ; j++) {
                int temp = neighbor[i].size() + neighbor[j].size();
                if (neighbor[i].count(j)) temp--;
                if (temp > res) res = temp;
            }
        }
        return res;
    }
};
