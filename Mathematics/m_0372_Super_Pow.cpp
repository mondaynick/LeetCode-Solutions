/*
  給定整數和一陣列，回傳其整數的陣列次方模1337，如a = 2, b = [1, 0]，則回傳1024

  遞迴關係：
    (a, [x1, ..., xn-1, xn]) = (a ^ xn) * [(a, [x1, ..., xn-2, xn-1]) ^ 10]
    (a, []) = 1
  快速冪運算：
    (a ^ e) = 1                              if e is 0
    (a ^ e) = a * [a ^ (e - 1)]              if e is odd
    (a ^ e) = [a ^ (e / 2)] * [a ^ (e / 2)]  if e is even
 */

class Solution {
private:
    int res = 1;
public:
    int myPow(int a, int e) {
        if (e == 0) return 1;
        a %= 1337;
        if (e % 2) {
            return a * myPow(a, e - 1) % 1337;
        } else {
            int temp = myPow(a, e / 2);
            return (temp * temp) % 1337;
        }
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int temp = b.back();
        b.pop_back();
        int res1 = myPow(a, temp) % 1337;
        int res2 = myPow(superPow(a, b), 10) % 1337;
        return (res1 * res2) % 1337;
    }
};
