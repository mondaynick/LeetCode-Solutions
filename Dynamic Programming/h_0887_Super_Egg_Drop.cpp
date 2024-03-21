/*
  假設面前有一棟從1到N共N層的大樓，然後提供k個雞蛋(k至少為1)，現在確定這棟樓存在樓層F滿足0<=F<=N，在這層樓將雞蛋
  扔下去，雞蛋恰好沒摔破(高於F的樓層都會破，低於F的樓層則不會)，最壞情況下，至少要扔幾次雞蛋，才能確定這個樓層

  利用動態規劃
 */

class Solution {
public:
    map<pair<int, int>, int> memo;

    int dp(int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;
        if (memo.count({k, n})) return memo[{k, n}];

        int res = INT_MAX, lo = 1, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int broken = dp(k - 1, mid - 1);
            int notBroken = dp(k, n - mid);
            if (broken > notBroken) {
                hi = mid - 1;
                res = min(res, broken + 1);
            } else {
                lo = mid + 1;
                res = min(res, notBroken + 1);
            }
        }
        return memo[{k, n}] = res;
    }

    int superEggDrop(int k, int n) {
        return dp(k, n);    
    }
};
