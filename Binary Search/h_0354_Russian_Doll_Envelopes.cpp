/*
  給出一些信封，每個信封的寬度和高度以整數對形式(w, h)表示，當一個信封A的寬度和高度，都比另一個
  信封B的寬度和高度都大時，B就可以放進A裡，如同俄羅斯娃娃，請計算最多有多少個信封能組成一組俄羅斯
  娃娃信封，即最多能嵌套幾層

  首先，先將所有信封依照寬度升冪排序，再將所有信封依照高度降冪排序，
  這是因為兩個寬度相同的信封不能相互包含，將其降冪代表最多只會有一個信封被選擇，
  排序後求其longest increasing subsequence長度，
  因為使用動態規劃會TLE，以下介紹使用二元搜尋
  -
  利用耐心排序，給定一些撲克牌，根據以下規則擺放：
  1. 只能把點數小的牌壓在點數大的牌上面
  2. 如果目前沒有任何牌堆或任何位置適合，則新建一個牌堆
  3. 如果目前的牌堆有多個牌堆可以選擇，則選擇最左邊的牌堆擺放
  最後牌堆數即為longest increasing subsequence長度
 */

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] > b[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> piles;
        for (int i = 0 ; i < envelopes.size() ; i++) {
            int poker = envelopes[i][1];
            int left = 0, right = piles.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (piles[mid] < poker) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (right >= piles.size()) piles.push_back(poker);
            else piles[right] = poker;
        }
        return piles.size();
    }
};
