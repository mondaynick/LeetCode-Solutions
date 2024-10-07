/*
  給定一個整數陣列citations，其中citations[i]代表某個研究者的第i篇公開論文被
  引用的總次數，回傳該研究者的H指數
  根據維基百科，H指數的定義如下：如果有一個研究者，他的所有公開n篇論文中至少有h篇
  個別至少被引用h次，且另外n - h篇被引用次數都不超過h次，那這個研究者的H指數就是h

  先將citations由大排到小，比較當前citations[i]和索引i
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0 ; i < citations.size() ; i++) {
            if (i + 1 > citations[i]) return i;
        }
        return citations.size();
    }
};
