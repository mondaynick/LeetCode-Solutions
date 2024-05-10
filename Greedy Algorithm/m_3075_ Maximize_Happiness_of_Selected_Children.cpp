/*
  給定大小為n的happiness陣列，分別代表n個小孩的快樂值，從中選出k個小孩，當選出某個小孩時，
  其餘所有小孩的快樂值皆會減1，最多減至0，求從n個小孩中選出k個小孩使得選出的小孩中快樂值總和最大為多少

  每次選擇快樂值最大的小孩，將其相加即得答案
 */

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long  count_time = 0, res = 0;

        while (k--) {
            long long temp = happiness.back() - count_time;
            if (temp < 0) temp = 0;
            count_time++;
            res += temp;
            happiness.pop_back();
        }

        return res;
    }
};
