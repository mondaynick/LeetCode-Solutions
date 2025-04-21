/*
  給定一個陣列 differences 和兩個整數 lower 和 upper ，回傳有多少個陣列 nums
  長度為 differences.size + 1 滿足以下條件：
   (1) lower <= nums[i] <= upper
   (2) nums[i + 1] - nums[i] == differences[i]
  
  由此可知， nums 的個數介於 (upper - lower + 1) - (maxValue - minValue) 之間
 */

using ll = long long;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll prefixSum = 0, minValue = 0, maxValue = 0;
        for (int difference: differences) {
            prefixSum += difference;
            if (prefixSum < minValue) minValue = prefixSum;
            if (prefixSum > maxValue) maxValue = prefixSum;
        }
        if (upper - lower + 1 < maxValue - minValue) return 0;
        return (upper - lower + 1) - (maxValue - minValue);
    }
};
