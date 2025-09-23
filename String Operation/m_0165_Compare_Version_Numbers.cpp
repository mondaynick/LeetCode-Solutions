/*
  給定兩個字串 version1 和 version2 ，分別代表版本號：
    (1) 如果 version1 版本比較早，回傳 -1
    (2) 如果 version2 版本比較早，回傳 1
    (3) 如果 version1 和 version2 版本相同，回傳 0

  先將字串切割再一一比較
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string part;
        stringstream ss1(version1), ss2(version2);
        while (getline(ss1, part, '.')) v1.push_back(stoi(part));
        while (getline(ss2, part, '.')) v2.push_back(stoi(part));

        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int a = (i < (int)v1.size()) ? v1[i] : 0;
            int b = (i < (int)v2.size()) ? v2[i] : 0;
            if (a < b) return -1;
            if (a > b) return 1;
        }
        return 0;
    }
};
