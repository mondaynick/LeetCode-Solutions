/*
  給定兩個整數陣列 spells 和 potions 以及一個整數 success ，其長度分別為 n 和 m ，其中 spells[i] 
  代表第 i 個咒語的強度而 potions[j] 代表第 j 個藥水的強度，如果一個咒語和藥水隻配對如果滿足其乘積
  至少為 success 則該配對視為成功的，回傳一個長度為 n 的整數陣列假設為 pairs，其中 pairs[i] 為可以
  與第 i 個咒語形成成功的配對之藥水之數量

  先將 spells 由小排到大，記得先記錄索引，然後再將 potions 由大排到小，可以看到排序後的 spells[0] 是
  spells 中最小值，假設已知我們找到一個索引值 x ，滿足當 i >= x 時， spells[0] * potions[i] < success
  且當 i < x 時， spells[0] * potions[i] >= success，那現在如果我們要求 spells[1] 對應的 x 值，可以
  看到排序後 spells[0] <= spells[1] ，所以 spells[1] 的 x 必定不會小於 spells[0] 的 x ，所以我們可以
  繼承 spells[0] 的值繼續往右找，同理 spells[2] 可以繼承 spells[1] 的 x 值、 spells[3] 可以繼承 spells[2]
  的 x 值、...以此類推
 */

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int, int>> newSpells(spells.size());
        for (int i = 0; i < spells.size(); ++i) {
            newSpells[i].first = spells[i];
            newSpells[i].second = i;
        }
        sort(newSpells.begin(), newSpells.end(), [](const pair<int, int> &left, const pair<int, int> &right) {
            return left.first < right.first;
        });
        sort(potions.begin(), potions.end(), greater<int>());
        int match = 0;
        vector<int> ans(spells.size());
        for (int i = 0; i < spells.size(); ++i) {
            while (match < potions.size() && (long long)newSpells[i].first * potions[match] >= success)
                ++match;
            ans[newSpells[i].second] = match;
        }
        return ans;
    }
};
