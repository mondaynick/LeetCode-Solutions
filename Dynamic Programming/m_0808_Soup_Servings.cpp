/*
  給定一個整數 n ，目前有兩碗湯 A 和 B ，分別有 n 毫升的湯，每一輪可以進行以下任一操作，
  且選擇任何操作的機率皆是 0.25 ：
    (1) 從 A 倒出 100 毫升的湯並從 B 倒出 0 毫升的湯
    (2) 從 A 倒出 75 毫升的湯並從 B 倒出 25 毫升的湯
    (3) 從 A 倒出 50 毫升的湯並從 B 倒出 50 毫升的湯
    (4) 從 A 倒出 25 毫升的湯並從 B 倒出 75 毫升的湯
  注意以下情況：
    (1) 沒有從 A 倒出 0 毫升的湯並從 B 倒出 100 毫升的湯這個選項
    (2) 倒湯時， A 和 B 是同時倒出來的
    (3) 若有任何碗裡面的湯小於你目前要對該碗倒的毫升數則將該碗剩下的湯全數倒光
  當有任一碗的湯已經被倒完時，結束所有操作，回傳 A 比 B 先倒完的機率 加上 0.5 乘以 A 和 B
  同時被倒完的機率

  利用動態規劃加上 memoization
 */

class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0;
        n = ceil((double)n / 25);
        return dp(n, n);
    }

    double dp(int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        } else if (a <= 0) {
            return 1;
        } else if (b <= 0) {
            return 0;
        }
        if (memo[a].count(b)) return memo[a][b];
        return memo[a][b] = 0.25 * (
            dp(a - 4, b) + dp(a - 3, b - 1) + dp(a - 2, b - 2) + dp(a - 1, b - 3)
        );
    }
private:
    unordered_map<int, unordered_map<int, double>> memo;
};
