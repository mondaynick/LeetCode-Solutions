/*
  給定num1[0...(m - 1)]和nums2[0...(n - 1)]，則假設nums3[0...(m*n - 1)]等於以下
  {
    nums1[0]*nums2[0], nums1[0]*nums2[1], ..., nums1[0]*nums2[n-1],
    nums1[1]*nums2[0], nums1[1]*nums2[1], ..., nums1[1]*nums2[n-1],
    ...
    nums1[m-1]*nums2[0], nums1[m-1]*nums2[1], ..., nums1[m-1]*nums2[n-1],
  }
  求nums3所有數字xor後的結果

  如果nums1有m個元素且m為奇數，代表nums2每個元素只會出現奇數次，故將nums2每個元素xor起來
  反之則num2每個元素只會出現偶數次，每個元素xor起來會變成0
  如果nums2有n個元素且n為奇數，代表nums1每個元素只會出現奇數次，故將nums1每個元素xor起來
  反之則num1每個元素只會出現偶數次，每個元素xor起來會變成0
 */

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = -1;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len2 % 2) {
            for (int ite: nums1) {
                res ^= ite;
            }
        } 
        if (len1 % 2) {
            for (int ite: nums2) {
                res ^= ite;
            }
        }
        return res ^ -1;
    }
};
