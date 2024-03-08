/*
  給定一陣列含有許多字串，求這些字串最長的前綴為何

  每次比較所有字串的第i個字是否相同
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        int i = 0;
        bool terminated = true;
        while (i < strs[0].length()) {
            char c = strs[0][i];
            for (int j = 1 ; j < strs.size() ; j++) {
                if (c != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
            i++;
        }
        return strs[0];
    }
};
