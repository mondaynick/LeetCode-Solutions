/*
  給定一個整數 n ，將 1 到 n 中所有整數之各項位數和相同的放在同個集合，求集合含有最多元素的數量

  利用 hash table
 */

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> memo;
        int maxSize = 0, maxCount = 0;
        for (int i = 1 ; i <= n ; ++i) {
            int temp = i, digit = 0;
            while (temp) {
                digit += temp % 10;
                temp /= 10;
            }
            ++memo[digit];
            if (memo[digit] > maxSize) maxSize = memo[digit];
        }
        for (auto [key, value]: memo) {
            if (value == maxSize) ++maxCount;
        }
        return maxCount;
    }
};
