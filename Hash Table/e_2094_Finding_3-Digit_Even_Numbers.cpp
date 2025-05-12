/*
  給定一個陣列 digits ，列出利用 digits 中的三個不同位置的數字來組成一個三位數所有的可能性

  利用 hash table
 */

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (auto digit: digits) ++count[digit];
        vector<int> res;
        for (int hunds = 1 ; hunds <= 9 ; ++hunds) {
            if (count[hunds] == 0) continue;
            --count[hunds];
            for (int tens = 0 ; tens <= 9 ; ++tens) {
                if (count[tens] == 0) continue;
                --count[tens];
                for (int units = 0 ; units <= 9 ; units += 2) {
                    if (count[units] == 0) continue;
                    res.push_back(100 * hunds + 10 * tens + units);
                }
                ++count[tens];
            }
            ++count[hunds];
        }
        return res;
    }
};
