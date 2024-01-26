/*
  給定n，回傳費氏數列第n項，若Fib(0) = 0, Fib(1) = 1

  根據定義利用動態規劃求解
 */

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int prev = 0, curr = 1;
        for (int i = 1 ; i < n ; i++) {
            int temp = curr;
            curr += prev;
            prev = temp;
        }
        return curr;
    }
};
