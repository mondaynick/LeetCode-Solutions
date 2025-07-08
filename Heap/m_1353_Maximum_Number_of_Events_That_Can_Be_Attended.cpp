/*
  給定一個二維陣列 events ，其中 events[i] = [si, ei] 代表第 i 項活動的開始時間為第 si 天且結束時間為第 ei 天，
  若在該活動這段期間內有參加任何一天的話則算參與該活動，且每一天只能選擇一個活動參加，請問最多可以參與多少活動

  利用 priority queue ，將已經開始的活動對結束時間做排序，優先參加結束時間早的活動，即可參與最多的活動
 */

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int result = 0, maxDay = 0, totalEvents = events.size();
        for (const vector<int> &event : events) {
            maxDay = max(maxDay, event[1]);
        }
        sort(events.begin(), events.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int day = 0, eventIdx = 0 ; day <= maxDay ; ++day) {
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            while (eventIdx < totalEvents && day == events[eventIdx][0]) {
                pq.push(events[eventIdx++][1]);
            }
            if (!pq.empty()) {
                pq.pop();
                ++result;
            }
        }
        return result;
    }
};
