/*
  給定兩個矩陣 nums1 和 nums2 ，回傳一個 2 x n 的矩陣 res ，其中
    res[0]為nums1出現但nums2沒出現的元素
    res[1]為nums2出現但nums1沒出現的元素

  利用set的不重複性和hash table的快速查找
 */

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<vector<int>> res(2, vector<int>(0));
        for (int ite: s1) {
            if (!s2.count(ite)) {
                res[0].push_back(ite);
            }
        }
        for (int ite: s2) {
            if (!s1.count(ite)) {
                res[1].push_back(ite);
            }
        }
        return res;
    }
};
