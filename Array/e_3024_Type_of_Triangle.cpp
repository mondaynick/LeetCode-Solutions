/*
  給定一個 size 為 3 的 nums ，其中 nums[i] 分別代表 3 個邊的長度，
  若此 3 個邊無法組成任意三角形，則回傳 "none" ，
  若此 3 個邊可以組成三角形且所有邊長度皆相同，則回傳 "equilateral" ，
  若此 3 個邊可以組成三角形且有兩個邊長度皆相同，則回傳 "isosceles" ，
  若此 3 個邊可以組成三角形且所有邊長度皆不同，則回傳 "scalene"

  利用給定條件求得
 */

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if ((nums[0] + nums[1] <= nums[2]) ||
        (nums[0] + nums[2] <= nums[1]) ||
        (nums[1] + nums[2] <= nums[0])) 
            return "none";
        if (nums[0] == nums[1] && nums[0] == nums[2])
            return "equilateral";
        else if (nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2])
            return "scalene";
        else
            return "isosceles";
    }
};
