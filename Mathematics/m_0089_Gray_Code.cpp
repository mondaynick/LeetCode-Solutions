/*
  給定一整數n，回傳n位元的所有格雷碼以二進位表示對應的十進位(從小到大)

  假設Gn代表n位元的所有格雷碼以二進位表示對應的十進位
  令 0Gn 代表將 Gn 中的每一個數字二進位表示法前面補0
  令 1Gn 代表將 Gn 中的每一個數字二進位表示法前面補1
  令 Gn^R 代表將 Gn 反向排序
  則Gn+1 = 0Gn, 1Gn^R，例如：
    G0 = [0]
    G1 = [0, 1] -> [0, 1]
    G2 = [00, 01, 10, 11] -> [00, 01, 11, 10]
    G3 = [000, 001, 011, 010, 100, 101, 111, 110] -> [000, 001, 011, 010, 110, 111, 101, 100]
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        
        while (n--) {
            for (int i = res.size() - 1, len = res.size() ; i >= 0 ; i--)
                res.push_back(res[i] + len);
        }

        return res;
    }
};
