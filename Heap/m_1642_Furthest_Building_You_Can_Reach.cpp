/*
  給定一陣列heights代表各個建築物的高度，起初你在heights[0]，若下個樓層比目前樓層低，你可以直接走過去，反之則你必須使用n個磚塊
  墊高或是使用1個梯子直接爬過去，回傳你可以走到最遠的建築物距離

  利用min heap，若heap的大小大於梯子的數量再去做決策
 */

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int len = heights.size();
        priority_queue<int> pq;
        for (int i = 1 ; i < len ; i++) {
            const int diff = heights[i] - heights[i - 1];
            if (diff <= 0) continue;
            pq.push(-diff);
            if (pq.size() <= ladders) continue;
            bricks += pq.top(); pq.pop();
            if (bricks < 0) return i - 1;
        }
        return len - 1;
    }
};
