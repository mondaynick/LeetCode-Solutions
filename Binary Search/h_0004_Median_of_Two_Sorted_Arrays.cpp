/*
  給定兩個已排序好的陣列，回傳將兩個陣列合併後的中位數
  
  給定一筆排序好的資料，求中位數有以下兩種情況；
  若該筆資料數為偶數，將資料切開使得左邊及右邊資料個數相等，則中位數為左邊最大和右邊最小相加除以2
  01   02   03 | 04   05   06 => 中位數為 (3 + 4) / 2 = 3.500
  若該筆資料為奇數，將資料切開使得左邊資料個數比右邊資料個數多一，則中位數為左邊最大
  01   02   03 | 04   05 => 中位數為 3.000
  
  給定兩筆排序好的資料，求中位數亦有以下兩種情況：
  若兩筆資料和為偶數，將資料切開需滿足以下三種情況
  (1) 左邊資料個數等於右邊資料個數
  (2) 上面資料的左邊最大值小於下面資料的右邊最小值
  (3) 下面資料的左邊最大值小於上面資料的右邊最小值
  則中位數為左邊資料最大值和右邊資料最小值相加除以2
  03   08 | 09   10
  02   04   06 | 12   18   20 => 中位數為 (8 + 9) / 2 = 8.500
  若兩筆資料和為奇數，將資料切開需滿足以下三種情況
  (1) 左邊資料個數比右邊資料個數多一
  (2) 上面資料的左邊最大值小於下面資料的右邊最小值
  (3) 下面資料的左邊最大值小於上面資料的右邊最小值
  則中位數為左邊資料最大值
  02   04   06 | 15
  01   07 | 08   10   17 => 中位數為7.000

  首先令上面資料為兩筆資料中最短者，再利用二分搜尋對上面資料做切開，透過公式即可求得下面資料的切入點
  根據切開不滿足以上情況時所做的調整，可分成以下兩種情況：
  若分隔線的右邊資料太小，則將上面資料的分隔線向右調整
  02   04 | 06   15
  01   07   08 | 10   17
  變成
  02   04   06 | 15
  01   07 | 08   10   17
  若分隔線的左邊資料太小，則將上面資料的分隔線向左調整
  02   04   06   08 | 10   17
  01 | 07   15
  變成
  02   04   06 | 08   10   17
  01   07 | 15
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) { // Let nums1 be the shorter array
            vector<int> temp;
            temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        int n1len = nums1.size();
        int n2len = nums2.size();
        int totalLeft = (n1len + n2len + 1) / 2; // Get the numbers of left element
        int left = 0;
        int right = n1len - 1;

        while (true) {
            int n1idx = left + (right - left) / 2;
            int n2idx = totalLeft - n1idx;

            int nums1LeftMax = (n1idx == 0) ? INT_MIN : nums1[n1idx - 1];
            int nums1RightMin = (n1idx == n1len) ? INT_MAX : nums1[n1idx];
            int nums2LeftMax = (n2idx == 0) ? INT_MIN : nums2[n2idx - 1];
            int nums2RightMin = (n2idx == n2len) ? INT_MAX : nums2[n2idx];

            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                if ((n1len + n2len) % 2 == 1) {
                    return max(nums1LeftMax, nums2LeftMax);
                } else {
                    return (double)(max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2;
                }
            } else if (nums1LeftMax > nums2RightMin) {
                right = n1idx - 1;
            } else {
                left = n1idx + 1;
            }
        }
    }
};
