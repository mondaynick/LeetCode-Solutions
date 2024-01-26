/*
  給定n個階梯數，求其爬樓梯的方法樹，若一次可以爬一或兩個階梯數

  求爬n個階梯的方法數相當於求解費氏數列第n + 1項，利用動態規劃求解
 */

class Solution {
public:
    int climbStairs(int n) {
        int prev = 0, curr = 1;
        for (int i = 1 ; i <= n ; i++) {
            int temp = curr;
            curr += prev;
            prev = temp;
        }
        return curr;
    }
};
