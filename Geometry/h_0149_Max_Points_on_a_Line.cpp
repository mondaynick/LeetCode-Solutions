/*
  給定二維坐標上的幾個點，回傳最多有幾個點為共線

  若三個點(x1, y1), (x2, y2), (x3, y3)為共線，則其外積會等於0
      | x1 y1 1 |
  det | x2 y2 1 | = 0
      | x3 y3 1 |
 */

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) return points.size();

        int maxValue = 0;
        for (int i = 0 ; i < points.size() ; i++) {
            for (int j = i + 1 ; j < points.size() - 1 ; j++) {
                int temp = 2;
                for (int k = 0 ; k < points.size() ; k++) {
                    if (i != k && j != k) {
                        int x1 = points[i][0], y1 = points[i][1];
                        int x2 = points[j][0], y2 = points[j][1];
                        int x3 = points[k][0], y3 = points[k][1];
                        if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0)
                            temp++;
                    }
                }
                if (temp > maxValue) maxValue = temp;
            }
        }

        return maxValue;
    }
};
