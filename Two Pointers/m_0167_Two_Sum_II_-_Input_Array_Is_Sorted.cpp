/*
  給定一排序好的陣列，回傳哪兩個位置相加的和會等於target

  利用two pointer，一個從頭、一個從尾，往中間收縮，
  若兩指標相加等於target，回傳兩指標位置，
  若兩指標相加大於target，代表數值應該要在小一點，尾指標往頭的方向移動一格，
  若兩指標相加小於target，代表數值應該要在大一點，頭指標往尾的方向移動一格
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while (start <= end) {
            if ((numbers[start] + numbers[end]) == target) {
                return {start + 1, end + 1};
            } else if (numbers[start] + numbers[end] < target) {
                start++;
            } else {
                end--;
            }
        }
        return {-1, -1};
    }
};
