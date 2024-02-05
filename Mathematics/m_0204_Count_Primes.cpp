/*
  給定一正整數n，回傳小於n且為正整數又質數的可能性有幾個

  利用Sieve of Eratosthenes
 */

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<int> arr (n, 1);
        arr[0] = arr[1] = 0;
        for (int i = 2 ; i < sqrt(n)+1 ; i++) {
            if (arr[i]) {
                for (int j = i*i ; j < n ; j+=i) {
                    arr[j] = 0;
                }
            }
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
};
