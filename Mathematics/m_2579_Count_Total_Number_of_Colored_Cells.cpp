/*
  給定整數 n ，回傳 n 的著色數，範例如下：
  n = 1, ans = 1
  █
  n = 2, ans = 5
    █
  █ █ █
    █
  n = 3, ans = 13
      █
    █ █ █
  █ █ █ █ █
    █ █ █
      █

  可以發線每次都會比上次多4, 8, 12, ...個，因此推導公式如下：
  f(n) = 1 + 4 * [1 + (n - 1)] * (n - 1) / 2
       = 1 + 2 * n * (n - 1)
 */

class Solution {
public:
    long long coloredCells(long long n) {
        return 1 + 2 * n * (n - 1);
    }
};
