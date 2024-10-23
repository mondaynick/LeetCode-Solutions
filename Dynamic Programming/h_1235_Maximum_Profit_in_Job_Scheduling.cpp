/*
  給定n項工作，每個工作開始時間與結束時間分別為startTime[i]到endTime[i]，收益為profit[i]，
  給定三個陣列startTime、endTime、profit，回傳工作間佔用時間不重疊的前提下，能夠到達的最大收
  益，如果一個工作結束時間是X，允許同時選擇一個開始時間為X的工作

  weight[i] = max(weight[i - 1], wis[startTime[i]] + profit[i])
 */

typedef struct {
    int startTime;
    int endTime;
    int profit;
} job;

bool cmp(job *x, job *y) {
    return x->endTime < y->endTime;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len = startTime.size();
        vector<job*> jobs(len, nullptr);
        for (int i = 0 ; i < len ; i++) {
            jobs[i] = new job{startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), cmp);
        vector<int> res(len + 1, 0);
        for (int i = 1 ; i <= len ; i++) {
            int s = jobs[i - 1]->startTime;
            int e = jobs[i - 1]->endTime;
            int p = jobs[i - 1]->profit;
            if (i == 0) {
                res[i] = p;
                continue;
            }
            int choose = p;
            for (int j = i - 2 ; j >= 0 ; j--) {
                if (jobs[j]->endTime <= s) {
                    choose += res[j + 1];
                    break;
                }
            }
            int notChoose = res[i - 1];
            res[i] = max(choose, notChoose);
        }
        return res.back();
    }
};
