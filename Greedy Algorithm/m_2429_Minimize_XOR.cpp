/*
  給定整數num1和num2，找出整數x使得滿足以下兩個條件
    (1) num1 xor x為最小
    (2) num2和x有相同數量的設置位元

  令c1為num1的設置位元數，c2為num2的設置位元數
  若c1 = c2，則x為num1，因為num1 xor num1 = 0必定為最小
    num1 = 01100  num2 = 01010
       x = 01100  ^ # of set bits = 2
  若c1 > c2，從num1中挑選c2個盡量大且為1的位元
    num1 = 01110  num2 = 01010
       x = 01100  ^ # of set bits = 2
  若c1 < c2，先從num1中挑選c2個盡量大且為1的位元，再從num1中挑選c2 - c1個盡量小且為0的位元
    num1 = 01000  num2 = 01010
       x = 01001  ^ # of set bits = 2
 */

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int target = 0, targetBits = 0;
        for (int i = 0 ; i < 32 ; i++) {
            if (num2 & (1 << i)) {
                targetBits++;
            }
        }
        for (int i = 31 ; i >= 0 && targetBits ; i--) {
            if (num1 & (1 << i)) {
                target |= (1 << i);
                targetBits--;
            }
        }
        for (int i = 0 ; i < 32 && targetBits ; i++) {
            if (!(num1 & (1 << i))) {
                target |= (1 << i);
                targetBits--;
            }
        }
        return target;
    }
};
