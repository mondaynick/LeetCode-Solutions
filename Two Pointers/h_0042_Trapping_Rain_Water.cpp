/*
  給定一個長度為n的num陣列，代表二維平面內一排寬度為1的柱子，每個元素nums[i]都是非負整數，
  表示第i個柱子的高度，求下雨時這些柱子能夠裝多少雨水

  利用two pointer，往左每次更新左邊最大，往右每次更新右邊最大
  尋訪第i根柱子的雨水量為min(leftMax, rightMax) - height[i]
  https://i.imgur.com/B9NnSpg.gif 參考至https://ithelp.ithome.com.tw/articles/10248985
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int leftMax = height[0], rightMax = height[len - 1];
        int res = 0;
        int left = 0, right = len - 1;
        while (left < right) {
            if (leftMax < rightMax) {
                leftMax = max(leftMax, height[left + 1]);
                res += leftMax - height[++left];
            } else {
                rightMax = max(rightMax, height[right - 1]);
                res += rightMax - height[--right];
            }
        }
        return res;
    }
};
