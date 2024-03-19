/*
  給定字串haystack和needle，若haystack存在needle則回傳符合的第一個字元之索引，否則回傳-1

  建立prefix function
    建立一個和needle相同大小的陣列prefix，初始全部為0，prefixLen = 0，index = 1
    若needle[prefixLen] == needle[index]，則將prefixLen加1後放至prefix[index]，index++
    若不相等且prefixlen為0，則index++
    不然prefixLen = prefix[prefixLen - 1]
  -
  利用KMP演算法
    初始化兩個指標textPtr和pattPtr分別指向haystack和needle的第0個字元，當textPtr < haystack.length()
      若haystack[textPtr] == needle[pattPtr]，則textPtr++且pattPtr++
      若不相等且pattPtr > 0，pattPtr = prefix[pattPtr - 1]
      不然，textPtr++
    不然，回傳-1
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        /* Build Prefix Function */
        vector<int> prefix (needle.length(), 0);
        int prefixLen = 0, index = 1;
        while (index < needle.length()) {
            if (needle[prefixLen] == needle[index]) {
                prefix[index] = ++prefixLen;
                index++;
            } else {
                if (prefixLen == 0) {
                    index++;
                } else {
                    prefixLen = prefix[prefixLen - 1];
                }
            }
        }
        
        /* KMP Algorithm */
        int textPtr = 0, pattPtr = 0;
        while (textPtr < haystack.length()) {
            if (haystack[textPtr] == needle[pattPtr]) {
                textPtr++;
                pattPtr++;
            } else if (pattPtr > 0) {
                pattPtr = prefix[pattPtr - 1];
            } else {
                textPtr++;
            }

            if (pattPtr == needle.length()) return textPtr - pattPtr;
        }
        return -1;
    }
};
