/*
  給定一個int陣列，陣列內的數字代表牆的高度，請輸出兩道牆之間最多可以存的水量

  利用two pointer，若left的高度大於right的高度，則將right往左移動，
  以找到可能比當前right更高的高度來乘載更多的水量，反之亦然
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = INT_MIN;
        while (left != right) {
            res = max(res, min(height[left], height[right]) * (right - left));
            if (height[left] > height[right]) right--;
            else left++;
        }
        return res;
    }
};
