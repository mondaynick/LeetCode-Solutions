/*
  給定一系列數字，求有哪些數字滿足該數字的數量超過整體的三分之一

  利用摩爾投票算法，但算完之後還要再遍歷一次所有數字，
  但因為摩爾投票算法無法確保過三分之一，所以還需要重新確認一次
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;

        int major1 = 0, major2 = 1, cnt1 = 0, cnt2 = 0;

        for (auto n: nums) {
            if (n == major1) {
                cnt1++;
            } else if (n == major2) {
                cnt2++;
            } else if (cnt1 == 0) {
                major1 = n;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                major2 = n;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (auto n: nums) {
            if (n == major1) cnt1++;
            if (n == major2) cnt2++;
        }
        if(cnt1 > nums.size() / 3) res.push_back(major1);
        if(cnt2 > nums.size() / 3) res.push_back(major2);
        return res;
    }
};
