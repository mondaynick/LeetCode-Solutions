/*
  給定兩個正整數 n 和 x ，計算有多少種方法可以將 n 表示成若干個不同的正整數的 x 次方的和，
  且我們需要將結果對 10 ^ 9 + 7 取模

  開一個一維陣列 powers ，其紀錄小於等於 n 中所有正整數的 x 次方，再利用動態規劃，對於每個
  k ^ x ，我們從 n 到 k ^ x 反向遍歷更新 dp[i] = dp[i] + dp[i - k ^ x] ，之所以要反
  向遍歷是因為我們要確保每個 x 次方的數只能被使用一次，最後 dp[i] 會等於將 i 表示為若干個不
  同正整數的 x 次方的和
 */

class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> powers;
        int base = 1;
        while (pow(base, x) <= n) {
            powers.push_back(pow(base, x));
            ++base;
        }

        for (int power : powers) {
            for (int i = n; i >= power; --i) {
                dp[i] = (dp[i] + dp[i - power]) % MOD;
            }
        }

        return dp[n];
    }
};
