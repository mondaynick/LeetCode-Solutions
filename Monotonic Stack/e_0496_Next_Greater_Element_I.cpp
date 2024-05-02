/*
  給定nums1和nums2，回傳nums1中對應到nums2下一個更大的元素，如果沒有更大的元素則存-1

  利用單調堆疊，每次push新元素e時，都要pop掉那些比e小的數字
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res (nums1.size());
        unordered_map<int, int> memo;
        stack<int> s;
        for (int i = nums2.size() - 1 ; i >= 0 ; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            memo[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        for (int i = 0 ; i < nums1.size() ; i++) {
            res[i] = memo[nums1[i]];
        }
        return res;
    }
};
