/*
  假設二維平面上有痕多圓形的氣球，這些圓形投影到x軸會形成一個區間，請問至少要射幾箭，
  才能射破全部的氣球

  此題相當於0435 Non-overlapping Intervals問題：
  1. 先對所有氣球終點數值做排序
  2. 每次選擇終點數值最早的氣求
  3. 每次選擇該氣球後將與該氣球重疊的氣球刪除
  (注意：氣球射到邊緣也是會爆，Ex.[1, 3]和[3, 4]若從3射出去則這兩顆氣球皆會爆炸)
 */

class Solution {
public:
    static bool cmp(const vector<int> a, const vector<int> b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int currEnd = intervals[0][1];
        int count = 1;
        for (vector<int> i: intervals) {
            if (i[0] > currEnd) {
                count++;
                currEnd = i[1];
            } else {
                continue;
            }
        }
        return count;
    }
};
