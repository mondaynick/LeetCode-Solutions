/*
  給定若干堆香蕉和整數h，求每天至少要吃幾根香蕉才可以在h天內把所有香蕉吃完
  題目限制每天最多只能選一堆香蕉開始吃，且該堆香蕉吃完後若未達今天限制仍需要等待隔天才可以選另外一堆

  最少需要1根香蕉，最多需要piles最大值根香蕉，利用binary search
 */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 0, right = 0;
        for (int p: piles)
            if (p > right)
                right = p;
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, mid, h)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    bool canFinish(vector<int> piles, int banana, int day) {
        long long int time = 0;
        for (int pile: piles) {
            time += pile / banana;
            if (pile % banana) time++;
        }
        return time <= day;
    }
};
