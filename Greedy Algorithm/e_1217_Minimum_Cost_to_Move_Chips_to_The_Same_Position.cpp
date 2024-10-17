/*
  總共有n個籌碼，position[i]代表第i個籌碼的位置，目標是移動所有籌碼到同一個位置，
  每次動作可以把某個籌碼從position[i]移動到其他位置：
    移動到position[i]+2或position[i]-2的成本為0
    移動到position[i]+1或position[i]-1的成本為1
  回傳要把所有籌碼移動到同一個位置所需要的最小成本

  因為移動偶數格不需要成本，先將所有起始位置在奇數格的籌碼移到1，成本為0，再將所有
  起始位置在偶數格的籌碼移到0，然後再將1的所有籌碼移到2或將2的所有籌碼移到1，因此
  取兩者最小值
 */

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddNum = 0, evenNum = 0;
        for (int ite: position) {
            if (ite % 2) {
                oddNum++;
            } else {
                evenNum++;
            }
        }
        return min(oddNum, evenNum);
    }
};
