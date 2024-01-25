/*
  給定兩個字串以二進位表示，輸出兩個字串相加後的結果並以字串為資料型別

  遍歷兩字串，從LSB開始往MSB遍歷，起初carry = '0'
  當被加數和加數相同時，sum = carry，carry = a[i]；當被加數和加數不同時，sum = !carry，carry不變，
  當i >= 0或j >= 0或carry還有東西時，重複上面步驟
 */

class Solution {
public:
    string addBinary(string a, string b) {
        char carry = '0';
        string s = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry == '1') {
            char ai = (i >= 0) ? a[i] : '0';
            char bj = (j >= 0) ? b[j] : '0';
            if (ai == bj) { // carry = a[i], sum = carry
                s += carry;
                carry = ai;
            } else { // carry not change, sum = !carry
                s += (carry == '0') ? '1' : '0';
            }
            i--, j--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
