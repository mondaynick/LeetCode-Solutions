/*
  給定一個 2 * n 的矩陣grid，有兩個機器人，分別要從左上角走到右下角，機器人所得的分數為沿途所經過的點數總和，
  並且走過該點數後該點數會被設為0，第一位機器人先走，他為了讓第二個機器人所獲的的點數最小，採取的最佳的路徑，
  求第二個機器人在第一個機器人採取最佳路徑後，為了使自己也獲得最大點數所採取最佳路徑所能得到的最大點數為何

  經過第一個機器人走後，第二個機器人能走的路線只有兩種選擇：
    從(0, 0)走到(0, n - 1)再往下到(1, n - 1)
    從(0, 0)往下到(1, 0)再走到(1, n - 1)
  因此若第一個機器人從(0, i)下去，則對應以上第二個機器人可以獲得的點數為：
    (0, i + 1) 到 (0, n - 1)
    (1, 0) 到 (1, i - 1)
  枚舉所有可能性，回傳最佳的結果
 */

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int len = grid[0].size();
        vector<long long> upsum(len, grid[0][0]), dnsum(len, grid[1][0]);
        for (int i = 1 ; i < len ; i++) {
            upsum[i] = upsum[i - 1] + grid[0][i];
            dnsum[i] = dnsum[i - 1] + grid[1][i];
        }
        long long res = LLONG_MAX;
        for (int i = 0 ; i < len ; i++) {
            long long uppath = (i == len - 1) ? 0 : upsum.back() - upsum[i];
            long long dnpath = (i == 0) ? 0 : dnsum[i - 1];
            res = min(res, max(uppath, dnpath));
        }
        return res;
    }
};
