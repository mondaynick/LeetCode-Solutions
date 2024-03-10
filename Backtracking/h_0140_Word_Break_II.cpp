/*
  給定一字串s，回傳此字串可以由wordDict中的單字如何組合而成，列出所有可能性

  wordBreak("catsanddog")
  -> wordBreak("") + indict("catsanddog")
  -> wordBreak("c") + indict("atsanddog")
  -> wordBreak("ca") + indict("tsanddog")
  -> wordBreak("cat") + indict("sanddog")
  -> wordBreak("cats") + indict("anddog")
  -> wordBreak("catsa") + indict("nddog")
  -> wordBreak("catsan") + indict("ddog")
  -> wordBreak("catsand") + indict("dog")
  -> wordBreak("catsandd") + indict("og")
  -> wordBreak("catsanddo") + indict("g")
 */

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict (wordDict.begin(), wordDict.end());
        return wordBreak(dict, s);
    }

    vector<string> wordBreak(unordered_set<string> dict, string s) {
        if (mem.find(s) != mem.end()) return mem[s];
        vector<string> res;
        if (dict.count(s)) res.push_back(s);
        for (int i = 1 ; i < s.length() ; i++) {
            string right = s.substr(i);
            if (!dict.count(right)) continue;

            string left = s.substr(0, i);
            vector<string> temp = append(wordBreak(dict, left), right);
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return mem[s] = res;
    }

    vector<string> append(vector<string> prefixes, string s) {
        vector<string> res;
        for (auto prefix: prefixes) res.push_back(prefix + " " + s);
        return res;
    }

    unordered_map<string, vector<string>> mem;
};
