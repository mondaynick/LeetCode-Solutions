/*
  給定一個整數陣列 nums ，分別代表編的長度，任意選擇三條邊可以組成一個三角形的解共有多少個

  三條邊要組成一個三角形的條件是任兩條邊的長度相加要大於第三條邊的長度，所以我們先對所有邊進
  行排序，就可以簡化成最小的兩邊大於最長的邊，因此利用 two pointer ，將 k 移動到不合法的
  位置，計算結果
 */

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int res = 0;
        for (int i = 0; i < len - 2; ++i) {
            if (nums[i] == 0) continue;
            int k = i + 2;
            for (int j = i + 1; j < len - 1; ++j) {
                while (k < len && nums[i] + nums[j] > nums[k]) {
                    ++k;
                }
                res += k - j - 1;
            }
        }
        return res;
    }
};
