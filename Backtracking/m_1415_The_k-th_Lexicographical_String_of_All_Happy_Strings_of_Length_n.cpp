/*
  Happy string 定義如下：
    (1) 任何一個字元皆是由 'a' 或 'b' 或 'c' 所組成
    (2) 任意兩個相鄰字元不相同
  給定 n 和 k ，回傳其長度為 n 的所有可能之 happy string 中其字典排序後的第 k 個為何(從1算起)

  利用 backtracking
 */

class Solution {
private:
    string res = "";
    int idx = 0;
    void handler(string temp, int n, int k) {
        if (temp.length() == n) {
            idx++;
            if (idx == k) res = temp;
            return;
        }
        if (temp == "") {
            handler(temp + 'a', n, k);
            handler(temp + 'b', n, k);
            handler(temp + 'c', n, k);
        } else {
            char c = temp.back();
            if (c == 'a') {
                handler(temp + 'b', n, k);
                handler(temp + 'c', n, k);
            } else if (c == 'b') {
                handler(temp + 'a', n, k);
                handler(temp + 'c', n, k);
            } else if (c == 'c') {
                handler(temp + 'a', n, k);
                handler(temp + 'b', n, k);
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        handler("", n, k);
        return res;
    }
};
