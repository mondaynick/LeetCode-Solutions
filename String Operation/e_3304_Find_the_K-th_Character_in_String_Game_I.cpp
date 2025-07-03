/*
  Alice 和 Bob 在玩遊戲，剛開始 Alice 有一個字串 "a" ，現在 Bob 一直向 Alice 的字串進行以下操作：
    產生一個新字串，該字串的每個字元替換為原本字元的下一個英文字母，若為 'z' 則換成 'a' ，
    並將其加入到原字串後面
  直到 Alice 的字串可以存取第 k 個(索引從 0 開始)字元時，回傳其字串的第 k 個字元為何
 */

class Solution {
public:
    char kthCharacter(int k) {
        string text = "a";
        while (text.length() <= k) {
            text += changeHandler(text);
        }
        return text[k - 1];
    }
private:
    string changeHandler(const string &text) {
        string temp;
        for (int i = 0 ; i < text.length() ; ++i) {
            if (text[i] == 'z') {
                temp += 'a';
            } else {
                temp += text[i] + 1;
            }
        }
        return temp;
    }
};
