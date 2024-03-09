/*
  給定一字串s，回傳此字串可以由wordDict中的單字如何組合而成，列出所有可能性

  利用backtracking，
 */

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s, dict);
    }
private:
    vector<string> append(const vector<string>& prefixes, const string& word) {
        vector<string> res;
        for (const auto& prefix: prefixes)
            res.push_back(prefix + " " + word);
        return res;
    }

    const vector<string>& wordBreak(string s, unordered_set<string>& dict) {
        if (mem.count(s)) return mem[s];
        vector<string> ans;
        if (dict.count(s)) ans.push_back(s);
        for (int i = 1 ; i < s.length() ; i++) {
            const string& right = s.substr(i);
            if (!dict.count(right)) continue;
            const string& left = s.substr(0, i);
            const vector<string> left_ans = append(wordBreak(left, dict), right);
            ans.insert(ans.end(), left_ans.begin(), left_ans.end());
        }
        return mem[s] = ans;
    }
    unordered_map<string, vector<string>> mem;
};
