/*
  給定一n邊凸多邊型及每個頂點上所擁有的權重，將其分割成n-2個三角形後，求每個三角形之頂點權重乘積的總和為最小

  dp[i][j] = 
    0, if j - i < 2 (因為小於三個點無法構成三角形)
    min i<k<j {dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]}, otherwise
 */

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int len = values.size();

        vector<vector<int>> dp (len, vector<int>(len, 0));
        for (int gap = 0 ; gap < len ; gap++) {
            for (int i = 0, j = gap ; j < len ; i++, j++) {
                if (j < i + 2) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INT_MAX;
                    for (int k = i + 1 ; k < j ; k++) {
                        int temp = dp[i][k] + dp[k][j] + values[i] * values[k] * values[j];
                        if (dp[i][j] > temp) dp[i][j] = temp;
                    }
                }
            }
        }
        return dp[0][len - 1];
    }
};
