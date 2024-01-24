/*
  給定兩字串s和t，輸出s和t中所有字母分別的個數是否相同

  遍歷字串s將其所有字元放到字典，在遍歷字串t，若在字典中找不到或是比s多則回傳false，反之為true
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map <char, int> dict;
        for (int _ = 0 ; _ < s.length() ; _++) {
            if (dict.find(s[_]) == dict.end())
                dict[s[_]] = 1;
            else
                dict[s[_]]++;
        }
        for (int _ = 0 ; _ < t.length() ; _++) {
            if (dict.find(t[_]) == dict.end())
                return false;
            else if (dict[t[_]] == 0)
                return false;
            else
                dict[t[_]]--;
        }
        return true;
    }
};
