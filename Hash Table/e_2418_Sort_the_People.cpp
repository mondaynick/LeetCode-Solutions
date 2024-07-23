/*
  給定每個人的名字及身高，根據身高降冪輸出

  利用排序
 */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> temp;
        vector<string> res;
        int n = names.size();

        for (int i = 0 ; i < n ; i++) {
            temp[-heights[i]] = names[i];
        }

        for (pair<int, string> t: temp) {
            res.push_back(t.second);
        }

        return res;
    }
};
