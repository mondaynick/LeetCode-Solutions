/*
  給定一個環形的陣列，返回一個等長的陣列，對應索引儲存下一個更大的元素，如果沒有更大的元素，就存-1

  利用單調堆疊且將原始陣列長度翻倍
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size());
        stack<int> s;
        for (int i = temperatures.size() - 1 ; i >= 0 ; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            res[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return res;
    }
};
