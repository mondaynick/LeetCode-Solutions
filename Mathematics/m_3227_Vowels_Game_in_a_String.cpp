/*
  給定一個字串 s ， Alice 和 Bob 正在玩一個遊戲，玩法如下：
    (1) 由 Alice 開始，再換 Bob ，依序輪流
    (2) Alice 每次會從字串 s 中刪除一個子字串滿足該子字串存在奇數個母音
    (3) Bobs 每次會從字串 s 中刪除一個子字串滿足該字串存在偶數個母音
    (4) 若該回合該人無法刪除字串則代表輸了(可能是字串為空或者是不存在任何符合條件的子字串)
  若兩邊都採取最佳解，如果最後 Alice 贏了回傳 true ，反之則回傳 false

  如果字串 s 擁有任何母音，則 Alice 必定會贏，原因如下：
    (1) s 擁有奇數個母音， Alice 第一次會將所有字元刪除， Bob 無法刪除， Alice 獲勝
    (2) s 擁有偶數個母音， Alice 第一次會刪除奇數個母音，剩下奇數個母音， Bob 無法刪除， Alice 獲勝
 */

class Solution {
public:
    bool doesAliceWin(string s) {
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (isVowel(s[i])) return true;
        }
        return false;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
