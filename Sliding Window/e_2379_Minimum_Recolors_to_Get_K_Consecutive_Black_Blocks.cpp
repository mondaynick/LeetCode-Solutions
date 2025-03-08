/*
  給定一個字串 blocks 和整數 k ，回傳欲得到長度為 k 且都是 'B' 的字串最少需將多少個 'W' 換成 'B'

  利用 sliding window
 */

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0, minimum;
        for (int i = 0 ; i < k ; i++) {
            if (blocks[i] == 'W') count++;
        }
        minimum = count;
        for (int i = k ; i < blocks.length() ; i++) {
            if (blocks[i] == 'W') count++;
            if (blocks[i - k] == 'W') count--;
            minimum = min(minimum, count);
        }
        return minimum;
    }
};
