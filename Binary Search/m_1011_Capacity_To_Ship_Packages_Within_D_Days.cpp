/*
  給定一個正整數陣列weights和一個正整數D，其中weights代表一系列貨物，weights[i]的值表示
  第i件物品的重量，貨物不可分割且必須按照順序傳輸，求貨船能夠在D天內運完所有貨物的最低運載能力

  因為貨物不可分割，最小不能小於貨物間最大重量，最大不會超過所有貨物和，利用binary search
 */

class Solution {
public:
    int getMax(vector<int> weight) {
        int res = 0;
        for (int w: weight) {
            if (w > res) res = w;
        }
        return res;
    }

    int getSum(vector<int> weight) {
        int res = 0;
        for (int w: weight) {
            res += w;
        }
        return res;
    }

    bool isValid(vector<int> weights, int days, int limit) {
        if (limit < getMax(weights)) return false;
        int res = 0;
        int capacity = limit;
        for (int w: weights) {
            if (capacity < w) {
                res++;
                capacity = limit;
            }
            capacity -= w;
        }
        res++;
        return res <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = getSum(weights) + 1;
        while (left + 1 != right) {
            cout << left << " " << right << endl;
            int mid = left + (right - left) / 2;
            if (isValid(weights, days, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
