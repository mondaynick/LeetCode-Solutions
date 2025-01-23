/*
  給定一個字串 s 和整數陣列 indices ， indices[i] = j 代表將 s[i] 放到 s 的第 j 個位置

  遍歷indices，根據定義操作
 */

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s;
        for (int i = 0 ; i < s.length() ; i++)
            res[indices[i]] = s[i];
        return res;
    }
};
