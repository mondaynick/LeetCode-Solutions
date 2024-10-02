/*
  給定多個區間，將有重複的區間合併成一塊

  先根據起始點大小遞增排序，每次比較當前區間的起始點是否小於當前紀錄區間的終點
 */

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        vector<int> curr = intervals[0];
        for (int i = 1 ; i < intervals.size() ; i++) {
            if (intervals[i][0] <= curr[1]) {
                curr[1] = max(curr[1], intervals[i][1]);
            } else {
                res.push_back(curr);
                curr = intervals[i];
            }
        }
        res.push_back(curr);
        return res;
    }
};
