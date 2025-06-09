/*
  給定一個整數 n 和整數 k ，回傳範圍 [1, n] 中依照字母遞增排序的第 k 小元素為何

  每次計算從 n 到 n + 1 之間有多少元素
 */

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            long long int step = 0, first = cur, last = cur + 1;
            while (first <= n) {
                step += min((long long int) n + 1, last) - first;
                first *= 10;
                last *= 10;
            }
            if (step <= k) {
                ++cur;
                k -= step;
            } else {
                cur *= 10;
                --k;
            }
        }
        return cur;
    }
};
