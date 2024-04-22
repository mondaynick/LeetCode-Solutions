/*
  給定一個陣列，該陣列存放最近幾天的氣溫，演算法需回傳一個陣列，計算對於每一天，至少
  還需等多少天，才能等到一個更暖和的氣溫，如果等不到那一天，便填0

  利用單調堆疊
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
