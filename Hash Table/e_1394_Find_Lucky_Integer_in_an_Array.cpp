/*
  給定一個陣列 arr ，幸運數字的定義為該數字和該數字出現在該陣列的次數相同，回傳該陣列的幸運數字為何，
  若無出現則回傳 -1 ，若出現多個則回傳數字最大者

  利用 hash table
 */

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int a : arr) {
            ++freq[a];
        }
        int res = -1;
        for (auto [key, value] : freq) {
            if (key == value) {
                if (key > res) res = key;
            }
        }
        return res;
    }
};
