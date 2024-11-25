/*
  如傳統的1A2B遊戲，A代表猜的數字有幾個和解答的數字和位置都一樣，B代表猜的數字有幾個和解答的數字一樣但位置不同

  遍歷secret和guess，初始化一個num陣列
  若secret[i] == guess[i]，則A加一
  否則若存在i, j使得secret[i]可以和guess[j]配對，則B加一
 */

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> num(10, 0);
        for (int i = 0 ; i < secret.length() ; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                if (num[secret[i] - '0']-- > 0) cows++;
                if (num[guess[i] - '0']++ < 0) cows++; 
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
