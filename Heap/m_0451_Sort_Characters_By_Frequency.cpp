/*
  給定一字串，將字串重新排列成出現最多次的放前面

  利用heap
 */

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        string res = "";

        for (auto c: s) {
            if (mp.find(c) == mp.end()) mp[c] = 1;
            else mp[c]++;
        }

        for (auto m: mp) pq.push({m.second, m.first});

        while (!pq.empty()) {
            pair<int, char> temp = pq.top(); pq.pop();
            while (temp.first--)
                res += temp.second;
        }

        return res;
    }
};
