/*
  給定一個山形陣列，回傳其中最大值

  若該索引位於頂峰，則左邊和右邊的值會小於該索引對應的值，回傳索引
  若該索引位於上坡，則右邊的值會大於該索引對應的值，頂峰要往右邊找
  若該索引位於下坡，則左邊的值會大於該索引對應的值，頂峰要往左邊找
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = arr.size() - 2;
        while (1) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
};
