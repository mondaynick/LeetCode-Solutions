/*
  給定一個整數 n 和一個二維陣列 queries ，存在一個一維陣列 powers 由最少 2 的 n 次方數字組成，
  且所有數字的和相加會等於 n ，且該陣列 powers 為遞增排序，對於每一個 queries[i] = [li, ri]，
  回傳其 powers[i] * powers[i + 1] * ... * powers[j - 1] * powers[j] 的值為何

  (1) 先記錄整數 n 換成二進位後有哪些位置是 1 ，記錄其索引
  (2) 再利用前綴和建立一個 presum 陣列和
  (3) 利用快速冪取得結果
 */

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int i = 0;
        while (n) {
            if (n & 1) powers.push_back(i);
            n >>= 1;
            ++i;
        }
        int len = powers.size();
        vector<int> presum(len + 1, 0);
        for (int i = 0; i < len; ++i) {
            presum[i + 1] = presum[i] + powers[i];
        }
        vector<int> res;
        for (vector<int> query : queries) {
            int exp = presum[query[1] + 1] - presum[query[0]];
            res.push_back(powmod(exp));
        }
        return res;
    }

private:
    long long powmod(long long exp) {
        long long res = 1, base = 2;
        long long MOD = 1000000007;
        while (exp) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
};
