/*
  給定一二維陣列，判斷該單字是否存在其中，注意走過的格子不可以再走，且每次只能往上下左右其一，
  回傳給定的字串陣列中，哪些字串為存在的

  利用字典樹
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
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, TrieNode* t, int i, int j, string path, vector<string>& res) {
        if (t->dict.find(board[i][j]) != t->dict.end()) t = t->dict[board[i][j]];
        else return;

        char c = board[i][j];
        path += c;
        if (t->dict.find('#') != t->dict.end()) {
            res.push_back(path);
            t->dict.erase('#');
        }

        board[i][j] = '*';
        if (i - 1 >= 0 && board[i - 1][j] != '*')
            dfs(board, t, i - 1, j, path, res);
        if (i + 1 < board.size() && board[i + 1][j] != '*')
            dfs(board, t, i + 1, j, path, res);
        if (j - 1 >= 0 && board[i][j - 1] != '*')
            dfs(board, t, i, j - 1, path, res);
        if (j + 1 < board[0].size() && board[i][j + 1] != '*')
            dfs(board, t, i, j + 1, path, res);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie trie;
        for (auto w: words) {
            trie.insert(w);
        }

        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[0].size() ; j++) {
                dfs(board, trie.root, i, j, "", res);
            }
        }

        return res;
    }
};
