/*
  給定gas和cost陣列，gas[k]陣列代表第k站可以加多少的油，cost[k]代表第k站到第k+1站需要花多少的油，
  回傳一個起點，可以走遍所有站一圈，若答案為無解則回傳-1

  若存量已減至0，則更換一個新的起點，若total gas小於total cost，則答案為無解
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr = 0;
        int start = 0;
        int total = 0;

        for (int i = 0 ; i < gas.size() ; i++) {
            curr += gas[i] - cost[i];

            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }

            total += gas[i] - cost[i];
        }

        return (total >= 0) ? start : -1;
    }
};
