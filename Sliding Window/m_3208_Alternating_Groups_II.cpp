/*
  給定一陣列 colors 和整數 k ，其中 colors[i] = 0 代表紅色且 colors[i] = 1 代表藍色，
  回傳colors中有多少個長度為 k 且兩兩相鄰顏色不同的元素個數

  利用 sliding window ，若 colors 長度為 n 則長度為 k 的元素個數共有 n + k - 1 個
 */

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int left = 0, right = 1;
        int count = 0;
        for (int i = 0 ; i < k - 1 ; i++)
            colors.push_back(colors[i]);
        while (right < colors.size()) {
            if (colors[right] != colors[right - 1]) {
                if (right - left >= k - 1) {
                    count++;
                }
            } else {
                left = right;
            }
            right++;
        }
        return count;
    }
};
