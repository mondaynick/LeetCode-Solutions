/*
  給定兩個已排序好的陣列nums1和nums2，合併成一個排序好的陣列(答案看nums1)

  同合併排序的排序之觀念
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[idx] = nums2[n - 1];
                n--;
            } else {
                nums1[idx] = nums1[m - 1];
                m--;
            }
            idx--;
        }
        while (n > 0) {
            nums1[idx] = nums2[n - 1];
            n--;
            idx--;
        }
    }
};
