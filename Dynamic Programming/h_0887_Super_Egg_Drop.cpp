/*
  假設面前有一棟從1到N共N層的大樓，然後提供k個雞蛋(k至少為1)，現在確定這棟樓存在樓層F滿足0<=F<=N，在這層樓將雞蛋
  扔下去，雞蛋恰好沒摔破(高於F的樓層都會破，低於F的樓層則不會)，最壞情況下，至少要扔幾次雞蛋，才能確定這個樓層

  首先定義superEggDrop(eggs, height)為共有eggs顆雞蛋和height個樓層之所需最小扔雞蛋次數，base case如下：
  (1) 若雞蛋只有1顆，唯一的方法就是從第一層慢慢往上丟，故最少需要扔height次，故superEggDrop(1, height) = height
  (2) 若樓層只有0層，顯然不用扔即可得到答案，最少需要扔0次，故superEggDrop(eggs, 0) = 0
  (3) 若樓層只有1層，最少需要扔1次，如果碎了代表F為0，反之則為1，故superEggDrop(eggs, 1) = 1
  -
  接著，我們需要決定從哪個樓層將雞蛋往下丟可以得到最小扔雞蛋次數，若從x樓層往下丟，其中1 ≤ x ≤ height：
  (1) 如果有碎則從以下樓層開始丟，方法數為superEggDrop(eggs - 1, x - 1)
  (2) 如果沒碎則從以上樓層開始丟，方法數為superEggDrop(eggs, height - x)
  因為需要考慮最壞情況，所以要取者兩個case之最大值，故
  superEggDrop(eggs, height) = min 1 ≤ x ≤ height max( superEggDrop(eggs - 1, x - 1) , superEggDrop(eggs, height - x) )
  -
  但如果利用linear search從1找到height實在是太慢了，以下介紹使用binary search:
  (1) 由 “如果有碎則從以下樓層開始丟，方法數為superEggDrop(eggs - 1, x - 1)” 可知當x越大時，其方法數會越多，為一個單調遞增函數
  (2) 由 “如果沒碎則從以上樓層開始丟，方法數為superEggDrop(eggs, height - x)” 可知當x越大時，其方法數會越小，為一個單調遞減函數
  畫出x-y圖，y軸表示表示所需的最少扔雞蛋次數，x軸表示從哪一個樓層將雞蛋往上丟，故兩函數之交點必等於以下
  min 1 ≤ x ≤ height max( superEggDrop(eggs - 1, x - 1) , superEggDrop(eggs, height - x) )
  利用binary search，如果當前樓層破的雞蛋數大於當前樓層沒破的雞蛋數，則右區間等於中間，反之則左區間等於中間
  最後在看左區間臨界值和右區間臨界值之何者所需扔雞蛋次數最小即得答案
  -
  為了消除重疊子問題，可以利用hash table來記錄已經算過的答案
 */

class Solution {
public:
    unordered_map<string, int> memo;
    int superEggDrop(int eggs, int height) {
        if (height < 2) return height;
        if (eggs == 1) return height;

        string key = to_string(eggs) + to_string(height);
        if (memo.count(key)) return memo[key];

        int left = 1, right = height;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int broken = superEggDrop(eggs - 1, mid - 1);
            int notBroken = superEggDrop(eggs, height - mid);
            if (broken > notBroken) {
                right = mid;
            } else if (broken < notBroken) {
                left = mid;
            } else {
                left = right = mid;
            }
        }
        int res = 1 + min(
            max(superEggDrop(eggs - 1, left - 1), superEggDrop(eggs, height - left)),
            max(superEggDrop(eggs - 1, right - 1), superEggDrop(eggs, height - right))
        );
        return memo[key] = res;
    }
};
