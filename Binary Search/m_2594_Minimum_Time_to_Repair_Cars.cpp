/*
  給定一個陣列 ranks 和整數 cars ，其中 ranks[i] 代表第 i 位技師的階級為 rank[i] ， cars 代表車子的數量，
  這些車子要分配給這些技師修理，已知階級為 n 的技師修理 r 輛車子需要 n * r * r 的時間，且所有技師同時運行，回
  傳修理所有車子所需的最少時間

  利用 binary search
 */

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right = (long long)cars * cars * ranks[0];
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            for (int rank: ranks) {
                count += sqrt(mid / rank);
            }
            if (count >= cars) right = mid;
            else left = mid;
        }
        return right;
    }
};
