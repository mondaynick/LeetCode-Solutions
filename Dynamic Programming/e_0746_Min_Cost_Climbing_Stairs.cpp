/*
  給定一個整數陣列cost，cost[i]是踏到階梯上第i階後需付得成本，付出該成本後就可以選擇再
  往上爬一或二階，你可以選擇從index 0或index 1這階開始，回傳爬完整個到達上方的最小成本

  定義動態轉移方程：到我這階可能是從小我一階跳一接過來也可能是小我兩階跳兩階過來
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return min(cost[0], cost[1]);

        vector<int> arr(cost.size());
        arr[0] = cost[0], arr[1] = cost[1];

        for (int i = 2 ; i < arr.size() ; i++) {
            arr[i] = cost[i] + min(arr[i - 1], arr[i - 2]);
        }
        return min(arr[cost.size() - 1], arr[cost.size() - 2]);
    }
};
