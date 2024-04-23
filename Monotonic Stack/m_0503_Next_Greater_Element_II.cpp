/*
  給定一個環形的陣列，返回一個等長的陣列，對應索引儲存下一個更大的元素，如果沒有更大的元素，就存-1

  利用單調堆疊且將原始陣列長度翻倍
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = 2 * n - 1 ; i >= 0 ; i--) {
            while (!s.empty() && s.top() <= nums[i % n]) {
                s.pop();
            }
            res[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]);
        }
        return res;
    }
};
