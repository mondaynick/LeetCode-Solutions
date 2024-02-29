/*
  給定一陣列，若該陣列具有重複的元素則回傳true，反之則回傳false

  利用hash table
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hasFound;
        for (auto n: nums) {
            if (hasFound.count(n)) {
                return true;
            } else {
                hasFound.insert(n);
            }
        }
        return false;
    }
};
