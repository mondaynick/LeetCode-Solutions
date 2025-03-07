/*
  給定整數 left 和 right ，回傳 left 到 right 之間的質數其相鄰兩者差最小且數字盡可能越小

  先利用 sieve of Eratosthenes 過濾出 left 到 right之間的質數，再比較兩兩質數間的差
 */

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[1] = false;
        for (int i = 2 ; i <= sqrt(right) ; i++) {
            if (isPrime[i]) {
                for (int j = 2 * i ; j <= right ; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> rangePrime;
        for (int i = left ; i <= right ; i++) {
            if (isPrime[i]) rangePrime.push_back(i);
        }
        vector<int> res = {-1, -1};
        int minVal = INT_MAX;
        for (int i = 1 ; i < rangePrime.size() ; i++) {
            if (rangePrime[i] - rangePrime[i - 1] < minVal) {
                res[0] = rangePrime[i - 1];
                res[1] = rangePrime[i];
                minVal = rangePrime[i] - rangePrime[i - 1];
            }
        }
        return res;
    }
};
