/*
  給定nums陣列，nums[i]代表位置i最多能夠跳躍的步數，現在確保一定可以跳到最後一格，
  請問最少要跳多少次才能跳過去

  farest紀錄目前最遠可達，curr紀錄目前最遠已達，count紀錄目前已跳躍次數
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int farest = 0;
        int curr = 0;
        for (int i = 0 ; i < nums.size() - 1 ; i++) {
            farest = max(farest, nums[i] + i);
            if (i == curr) {
                count++;
                curr = farest;
            }
        }
        return count;
    }
};
