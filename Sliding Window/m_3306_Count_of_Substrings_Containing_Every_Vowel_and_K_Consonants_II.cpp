/*
  給定一個字串 word 和一整數 k ，回傳 word 中共有多少個子字串滿足以下兩個條件：
  (1) 所有母音 a, e, i, o, u 皆至少出現一次
  (2) 子音恰好出現 k 次

  利用 sliding window ，若 word[i...j] 恰好符合則 word[i...k] 且 k >= j 
  時都沒出現子音則也會符合條件
 */

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long left, right = 0, res = 0, vowel = 0, consonant = 0;
        long long len = word.length();
        unordered_set<char> isvow({'a', 'e', 'i', 'o', 'u'});
        unordered_map<char, int> memo;
        vector<long long> consecutive(len);
        long long count = 0;
        for (int i = len - 1 ; i >= 0 ; i--) {
            if (isvow.count(word[i])) {
                count++;
            } else {
                count = 0;
            }
            consecutive[i] = count;
        }
        for (left = 0 ; left < len ; left++) {
            while (right < len && (vowel < 5 || consonant < k)) {
                char c = word[right];
                if (isvow.count(c)) {
                    memo[c]++;
                    if (memo[c] == 1) vowel++;
                } else {
                    consonant++;
                }
                right++;
            }
            if (vowel == 5 && consonant == k) {
                res += 1 + (right < len ? consecutive[right] : 0);
            }
            char c = word[left];
            if (isvow.count(c)) {
                memo[c]--;
                if (memo[c] == 0) vowel--;
            } else {
                consonant--;
            }
        }
        return res;
    }
};
