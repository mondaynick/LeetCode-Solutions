/*
  給定一個陣列 nums 和整數 k ，可以對陣列執行以下操作：
    求出一個整數 h 滿足陣列中大於 h 的元素均相同
    將陣列中大於 h 的元素均改成 h
  以上為一次操作，求將陣列 nums 中每個元素變成 k 需進行以上操作幾次

  若有元素小於 k ，則陣列的元素最後都會小於 k ，即為不可能，
  否則查看陣列中有多少種元素(不包含 k )
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> memo;
        int minValue = INT_MAX;
        for (int num: nums) {
            if (num < k) return -1;
            minValue = min(minValue, num);
            memo.insert(num);
        }
        return memo.size() - (minValue == k);
    }
};
