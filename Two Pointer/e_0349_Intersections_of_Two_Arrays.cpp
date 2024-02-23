/*
  給定兩個陣列，輸出兩個陣列的交集並由小到大排列，記得因為是集合，所以回傳的答案中元素不會重複

  將兩陣列排序，依序遍歷兩陣列
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = 0, n2 = 0;
        int n1len = nums1.size(), n2len = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        while (n1 < n1len && n2 < n2len) {
            if (nums1[n1] < nums2[n2]) {
                n1++;
            } else if (nums1[n1] > nums2[n2]) {
                n2++;
            } else {
                if (res.size() == 0 || nums1[n1] != res[res.size() - 1])
                    res.push_back(nums1[n1]);
                n1++;
                n2++;
            }
        }
        return res;
    }
};
