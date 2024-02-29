/*
  建立一棵字典樹，並實作以下三個API：
    insert(word)：插入word到字典樹中
    search(word)：找尋字典樹是否存在word
    startsWith(prefix)：找尋字典樹是否存在以prefix開頭

  利用map往下建構一棵樹
 */

class TrieNode {
public:
    unordered_map<char, TrieNode*> dict;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* ite = root;
        for (auto w: word) {
            if (ite->dict.find(w) == ite->dict.end()) {
                ite->dict[w] = new TrieNode;
            }
            ite = ite->dict[w];
        }
        ite->dict['#'] = NULL;
    }
    
    bool search(string word) {
        TrieNode* ite = root;
        for (auto w: word) {
            if (ite->dict.find(w) == ite->dict.end())
                return false;
            ite = ite->dict[w];
        }
        return ite->dict.find('#') != ite->dict.end();
    }
    
    bool startsWith(string prefix) {
        TrieNode* ite = root;
        for (auto p: prefix) {
            if (ite->dict.find(p) == ite->dict.end())
                return false;
            ite = ite->dict[p];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
