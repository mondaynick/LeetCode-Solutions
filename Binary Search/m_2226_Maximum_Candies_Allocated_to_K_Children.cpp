/*
  給定一個陣列 candies 代表共有多少個糖果堆即整數 k ，而糖果堆可以分成更小的糖果堆，
  但不能將兩個糖果堆合併成為更大的糖果堆，若要將糖果分給 k 個小朋友，每個小朋友只能選
  擇一個糖果堆拿取糖果且所有小朋友要拿到一樣的糖果數量，請問每個小朋友可以拿到的糖果最
  大值為何

  利用 binary search
 */

class Solution {
private:
    bool check(vector<int>& candies, long long k, long long per) {
        long long  res = 0;
        for (long long ite: candies) {
            res += ite / per;
            if (res >= k) break;
        }
        return res >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long maxCan = 0, totalCan = 0;
        for (long long ite: candies) {
            if (ite > maxCan) maxCan = ite;
            totalCan += ite;
        }
        if (totalCan < k) return 0;
        
        long long left = 1, right = totalCan + 1;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            if (check(candies, k, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
