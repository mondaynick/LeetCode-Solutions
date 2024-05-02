/*
  給定nums和k，回傳每個視窗大小為k的最大值為何，例如：
  Window Position             Max
  --------------------------  ---
  [1  3  -1] -3  5  3  6  7   3
   1 [3  -1  -3] 5  3  6  7   3
   1  3 [-1  -3  5] 3  6  7   5
   1  3  -1 [-3  5  3] 6  7   5
   1  3  -1  -3 [5  3  6] 7   6
   1  3  -1  -3  5 [3  6  7]  7
   因此回傳陣列[3, 3, 5, 5, 6, 7]

  利用單調佇列，每次push新元素e時，都要pop掉那些比e小的數字
 */

class MonotonicQueue {
public:
    void push(int e) {
        while (!_data.empty() && e > _data.back())
            _data.pop_back();
        _data.push_back(e);
    }

    void pop() {
        _data.pop_front();
    }

    int max() {
        return _data.front();
    }
private:
    deque<int> _data;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> res;
        for (int i = 0 ; i < nums.size() ; i++) {
            q.push(nums[i]);
            if (i - k + 1 >= 0) {
                res.push_back(q.max());
                if (nums[i - k + 1] == q.max()) q.pop();
            } 
        }
        return res;
    }
};
