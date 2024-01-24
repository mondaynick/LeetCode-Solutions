/*
  透過給定的API isBadVersion來找出第一個損壞的版本

  透過二分搜尋法，如果當前是壞掉的則判斷是否為第一個或前一個是否是好的，是則回傳當前位置，
  否則往前面尋找，如果當前不是壞掉則往後面尋找
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int lo = 0, hi = n;
        while (lo <= hi) {
            long long int mi = (lo + hi) / 2;
            if (isBadVersion(mi)) {
                if (mi == 1 || !isBadVersion(mi - 1))
                    return mi;
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        return 0;
    }
};
