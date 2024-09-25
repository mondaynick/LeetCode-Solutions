/*
  給定二維陣列，陣列中每個元素[start, end]代表活動嘚開始時間和結束時間，若要完成多個活動，則最少可以刪除幾項活動

  1. 先對所有活動結束時間做排序
  2. 每次選擇結束時間最早的活動
  3. 每次選擇該活動後將與該活動衝突的活動刪除
 */

class Solution {
public:
    static bool cmp(const vector<int> a, const vector<int> b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int currEnd = intervals[0][0];
        int count = 0;
        for (vector<int> i: intervals) {
            if (i[0] >= currEnd) {
                count++;
                currEnd = i[1];
            } else {
                continue;
            }
        }
        return intervals.size() - count;
    }
};
