/*
  Tribonacci Sequence Tn定義為
  T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
  給定n並回傳Tn

  利用動態規劃
 */

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        else if (n == 1 || n == 2) return 1;
        vector<int> arr (38, 0);
        arr[1] = arr[2] = 1;

        for (int i = 3 ; i <= n ; i++)
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        return arr[n];
    }
};
