/*
  給定一堆石頭，每個石頭皆有重量，每次取這些石頭中重量最大的兩顆去撞擊，分為兩種情況：
    若兩顆石頭重量相等，則相撞後會摧毀
    若兩顆石頭重量不同，則相撞後只會留下一顆重量為原本兩重量差值的石頭
  求最後會剩下多少重量的石頭，若石頭皆被摧毀則回傳0

  利用heap每次取出前兩大重量的石頭作處理
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto s: stones) pq.push(s);

        while (pq.size() > 1) {
            int p = pq.top(); pq.pop();
            int q = pq.top(); pq.pop();
            if (p != q) {
                pq.push(p - q);
            }
        }

        if(pq.size()) return pq.top();
        return 0;
    }
};
