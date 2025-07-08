/*
  給定一個二維陣列 events 和整數 k ，其中 events[i] = [si, ei, vi] 代表該活動的開始時間為 si 且結束時間為 ei ，
  以及若參加該場活動可以獲得value 為 vi，若每個時間點只能參與一場活動，且若參與該活動需從頭參加到結束，你最多可以參加
  ｋ 場活動，回傳可獲得的最大 value 為何

  先對所有活動的結束時間做排序，定義 dp[i][j] 為前 i 場活動中最多參與 j 場其獲得的 value ，轉移方程如下：
    dp[i][j] = max(
      dp[nonOverlapIndex][j - 1] + events[i - 1][2]  // 若參與第 i 場活動
      dp[i - 1][j]                                   // 若不參與第 i 場活動
    )
  定義 nonOverlapIndex 為該活動之前與其活動不衝突之索引最大值，可以利用 binary search 獲得
 */

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int totalEvents = events.size();
        vector<vector<int>> dp(totalEvents + 1, vector<int>(k + 1, 0));
        sort(events.begin(), events.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[1] < rhs[1];
        });
        for (int currEventIdx = 1 ; currEventIdx <= totalEvents ; ++currEventIdx) {
            int left = 0, right = currEventIdx;
            while (left + 1 < right) { // left be allowed
                int mid = left + (right - left) / 2;
                if (events[mid - 1][1] < events[currEventIdx - 1][0]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            int nonOverlapIdx = left;
            // 
            for (int hasAttended = 1 ; hasAttended <= k  ; ++hasAttended) {
                dp[currEventIdx][hasAttended] = max(
                    dp[nonOverlapIdx][hasAttended - 1] + events[currEventIdx - 1][2],
                    dp[currEventIdx - 1][hasAttended]
                );
            }
        }
        return dp.back().back();
    }
};
