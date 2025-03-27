/*
  給定一個陣列 nums ，定義若存在元素 x 使得在該陣列中的出現次數超過其陣列長度的一半，
  則該元素稱為 dominant element ，你可以將陣列從索引 i 切割將陣列 [0, 1, ..., m - 1]
  分割成 [0, ..., i] 和[i + 1, ..., m - 1] ，且一個合法的切割定義如下：
    (1) 0 <= i < i - 1
    (2) [0, ..., i] 和 [i + 1, ..., m - 1] 和原陣列有相同的 dominant element
  求最小索引 i ，若不存在則回傳 -1

  先計算出 dominant number 為何，在透過遍歷求出最小索引
 */

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int domi, maxFreq = 0;
        int len = nums.size();
        unordered_map<int, int> count;
        for (int num: nums) {
            int temp = ++count[num];
            if (temp > maxFreq) {
                maxFreq = temp;
                domi = num;
            }
        }
        int freq = 0;
        for (int i = 0 ; i < len - 1 ; i++) {
            if (nums[i] == domi) freq++;
            if ((freq * 2 > (i + 1)) && ((maxFreq - freq) * 2 > (len - i - 1)))
                return i;
        }
        return -1;
    }
};
