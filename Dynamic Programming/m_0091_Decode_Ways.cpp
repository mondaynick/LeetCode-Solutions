/*
  給定一字串，輸出其編碼方式有幾種

  如果上一個不為0則加上累計到上一個的編碼數，如果上兩個可以組成則加上累計到上兩個的編碼數
 */

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0') return 0;
        if (s.length() == 1 && s[0] != '0') return 1;
        int len = s.length();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        for (int i = 2 ; i <= len ; i++) {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
                dp[i] += dp[i - 2];
        }
        return dp[len];
    }
};
