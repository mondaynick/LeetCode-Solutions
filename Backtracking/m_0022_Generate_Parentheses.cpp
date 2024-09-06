/*
    給定整數n，回傳n對括弧的所有合法組合，如n = 3則輸出"((()))","(()())","(())()","()(())","()()()"

    利用backtracking，首先定義終止條件：
    (1) 若 left < 0 或 right < 0 肯定不合法
    (2) 若 right < left 代表右括弧用得比左括弧多也是不合法
    (3) 若 left == 0 且 right == 0 則表示合法括弧對產生
    否則，嘗試加入左括弧或右括弧
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        handler(n, n, temp, res);
        return res;
    }

    void handler(int left, int right, string temp, vector<string>& res) {
        if (left < 0 || right < 0) return;
        if (right < left) return;
        if (left == 0 && right == 0) {
            res.push_back(temp);
            return;
        }

        temp.push_back('(');
        handler(left - 1, right, temp, res);
        temp.pop_back();

        temp.push_back(')');
        handler(left, right - 1, temp, res);
        temp.pop_back();
    }
};
