/*
  給定字串 word 和整數 numFriends ， 這個遊戲可以執行多輪，每一輪定義如下：
    (1) 將字串 word 分割成 numFriends 等分，每一等分不得為空字串
    (2) 將所有分割後的子字串放入箱子中
  當遊戲結束後，回傳箱子中的子字串其字母排序最大者

  考慮邊界條界，若 numFriends 為 1 則回傳 word ，
  欲找尋子字串其字母排序最大者，肯定是越長越好，但這個子字串的長度也有上限，假設找尋的子字串
  索引範圍為 [i, i + k) ，其必須滿足以下條件：
    (1) i + k <= word.length ：子字串不能越界
    (2) word.length - k >= numFriends - 1 ：剩下的子字串要可以分給剩下的朋友
  將以上兩行整理如下：
    (1) k <= word.length - i
    (2) k <= word.length - numFriends + 1
  要滿足以上兩個條件， k 必須取 word.length - i 和 word.length - numFriends + 1 兩者的最小值 
 */

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;

        int len = word.length();
        string res = "";
        for (int i = 0 ; i < len ; ++i) {
            int k = min(len - i, len - numFriends + 1);
            res = max(res, word.substr(i, k));
        }
        return res;
    }
};

/*
    [i, i + k)

    i + k <= word.length   => k <= word.length - i
    word.length - k >= numFriends - 1   => k <= word.length - numFriend + 1
*/
