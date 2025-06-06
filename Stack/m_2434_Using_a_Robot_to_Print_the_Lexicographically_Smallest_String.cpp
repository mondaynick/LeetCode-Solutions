/*
  給定一個字串 s ，你可以不斷執行以下操作：
  (1) 把字串 s 的第一個字元爲給機器人暫存
  (2) 從機器人的暫存中拿出最後一個字元寫在紙上
  直到字串 s 和機器人的暫存皆為空字串，找出最小字典排序的紙上句子

  很明顯暫存的操作是用堆疊操作，要得到最小字典排序，需要持續關注目前最小字元爲何，
  當字母放進堆疊後，需要知道這個字母是不是目前最小的，如果是則拿出來將其放進結果中
 */

class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        stack<char> stk;
        string res = "";
        auto hasSmaller = [&](char pos) {
            for (int i = 0 ; i < pos - 'a' ; ++i)
                if (freq[i] > 0) return true;
            return false;
        };

        for (auto c: s) ++freq[c - 'a'];
        for (auto c: s) {
            stk.push(c);
            --freq[c - 'a'];
            while (!stk.empty()) {
                char temp = stk.top();
                if (hasSmaller(temp)) break;
                res += stk.top();
                stk.pop();
            }
        }
        return res;
    }
};
