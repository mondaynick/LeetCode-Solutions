/*
  給定字串s和一堆字串wordDict，若字串s可以由wordDict的字串所組成(可重複取)則回傳true，反之則回傳false

  利用動態規劃，欲求解s[0:i]是否可以由wordDict所構成，可以檢查s[0:j-1]和[j:i]是否皆可構成
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto w: wordDict) dict.insert(w);
        vector<bool> dp (s.length() + 1, false);
        dp[0] = true;

        for (int i = 1 ; i <= s.length() ; i++) {
            for (int j = 0 ; j < i ; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};
