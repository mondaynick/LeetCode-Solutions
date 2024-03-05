/*
  設計以下API：
    WordDictionary()：實例化WordDictionary
    addWord()：加入這個單字到WordDictionary
    search()：查詢這個單字是否存在WordDictionary，"."代表萬用字元

  利用字典樹加DFS
 */

class TrieNode {
public:
    unordered_map<char, TrieNode*> dict;
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* ite = root;
        for (auto w: word) {
            if (ite->dict.find(w) == ite->dict.end()) {
                ite->dict[w] = new TrieNode;
            }
            ite = ite->dict[w];
        }
        ite->dict['#'] = NULL;
    }
    
    bool searchWord(string word, TrieNode* root) {
        if (!root) return false;

        TrieNode* ite = root;
        for (int i = 0 ; i < word.length() ; i++) {
            if (word[i] == '.') {
                for (auto d: ite->dict) {
                    if (d.first != '#' && searchWord(word.substr(i + 1), ite->dict[d.first]))
                        return true;
                }
                return false;
            } else if (ite->dict.find(word[i]) == ite->dict.end()) {
                return false;
            } else {
                ite = ite->dict[word[i]];
            }
        }
        return ite->dict.find('#') != ite->dict.end();
    }

    bool search(string word) {
        TrieNode* ite = root;
        return searchWord(word, ite);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
