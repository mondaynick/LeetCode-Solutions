/*
  給定一個整數陣列boxTypes和整數truckSize，
  boxTypes[0]和[1]分別代表每個這種盒子的個數和這種盒子內裝有的單位數
  在盒子總數不超過truckSize的情況下，可乘載的最大單位數為何

  對盒子的單位數從大排到小，利用greedy method
 */

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int res = 0;
        for (vector<int> box: boxTypes) {
            int count = box[0];
            int weight = box[1];
            while (count > 0 && truckSize > 0) {
                count--;
                truckSize--;
                res += weight;
            }
        }
        return res;
    }
private:
    static bool cmp(vector<int> a, vector<int> b) {
        return b[1] < a[1];
    }
};
