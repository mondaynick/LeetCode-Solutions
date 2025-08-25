/*
  給定一個陣列 nums ，回傳如果要將 1 個元素刪除後，子陣列其元素全為 1 的最大長度

  每次比較以下兩者何止最大並更新:
    1. 當前 1 的子陣列和上一個 1 的子陣列
    2. 上一個 1 的子陣列和上上一個 1 的子陣列
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = INT_MIN;
        bool isVisited0 = false;
        int curr = 0, prev = 0;
        for (int num : nums) {
            if (num == 0) {
                isVisited0 = true;
                res = max(res, curr + prev);
                prev = curr;
                curr = 0;
            } else {
                ++curr;
            }
        }
        res = max(res, curr + prev);
        return (isVisited0) ? res : (res - 1);
    }
};
