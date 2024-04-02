/*
  若一個字串s同構於另一個字串t，相當於s的所有字元皆可替換成t的所有字元，且字元間的對應為一對一且映成

  利用兩個字典紀錄上次某個字元的最後一次訪問所在的位置，
  若兩個字典所紀錄上次某個字元所在的位置不同，則代表兩字串不同構
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> memoS, memoT;
        for (int i = 0 ; i < s.length() ; i++) {
            if (memoS[s[i]] != memoT[t[i]]) return false;
            memoS[s[i]] = i + 1;
            memoT[t[i]] = i + 1;
        }
        return true;
    }
};
