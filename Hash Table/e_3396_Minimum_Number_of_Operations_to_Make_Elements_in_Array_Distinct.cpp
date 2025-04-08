/*
  給定一個陣列 nums ，每次執行刪除操作只能刪除陣列的前 3 個元素，若陣列不足 3 個元素則刪除全部元素，
  回傳欲使陣列的每個元素之間的數值不重複．需要執行多少次刪除操作

  從陣列的後面遍歷到前面，找到第一個重複的元素即可知道需要執行多少次刪除操作
 */

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> memo;
        for (int i = nums.size() - 1 ; i >= 0 ; --i) {
            if (memo.count(nums[i]))
                return (i / 3) + 1;
            else
                memo.insert(nums[i]);
        }
        return 0;
    }
};
