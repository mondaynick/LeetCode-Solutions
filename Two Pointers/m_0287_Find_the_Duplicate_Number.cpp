/*
  給定一陣列，若該陣列長度為n + 1，則陣列中的數字只會出現1到n，回傳該陣列中重複的數字為何

  因為陣列有n + 1個數字，而陣列的數字只會出現1到n，根據Pigeonhole Principle，必然會出現兩個重複的數字
  -
  利用Tortoise and Hare Algorithm(或稱Floyd's Cycle Detection Algorithm)
  Round 1:
    假設剛開始烏龜和兔子皆在S地，烏龜爬得比較慢，一次走一步，而兔子跑得比較快，一次走兩步，最後他們相遇在M地
  Round 2:
    目前兔子一樣在M地，而烏龜放到原本的起點S地，且規定兩個動物一次都只有一步，最終他們相遇的地方C地即是解答
  -
  以下為證明：
    假設M地到C地的距離為l，C地到M地的距離為x，則M地到C地的距離為c-x
    在Round 1中：
      兔子共走了l + nc + x，而烏龜共走了l + x，故可列出以下等式：
      l + nc + x = 2(l + x)  =>  l + x = nc
    在Round 2中：
      兔子共走了l + x + l，而烏龜共走了l，故可列出以下等式，且代入round 1所得之結果：
      l + x + l = nc + l
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int h = nums[0], t = nums[0];
        h = nums[nums[h]], t = nums[t];

        // First Meet
        while (h != t)
            h = nums[nums[h]], t = nums[t];
        t = nums[0];

        // Second Meet
        while (h != t)
            h = nums[h], t = nums[t];
        return h;
    }
};
