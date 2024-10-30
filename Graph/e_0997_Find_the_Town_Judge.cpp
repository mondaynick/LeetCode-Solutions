/*
  在一個小鎮裡，共n個居民被編號為1到n，傳言其中一個居民其實是秘密的小鎮法官，
  如果小鎮法官存在，那麼：
    a. 該法官不信任任何人
    b. 所有人除了法官都信任小鎮法官
    c. 只有剛好一個人滿足前兩項條件
  給定一個向量trust，trust[i] = [a, b]代表a居民信任b居民，如果小鎮法官存在
  ，且身份可以被判斷，回傳小鎮法官的編號，否則回傳-1

  可以將以上問題轉換成有向圖，每個頂點代表居民1到n，若a居民信任b居民，則建立一
  條邊從頂點a指向頂點b，遍歷完trust陣列後，判斷是否有一頂點其入度數為n-1且出
  度數為0，則該頂點即為小鎮法官，否則不存在小鎮法官
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n, 0);
        vector<int> outDegree(n, 0);
        for (vector<int> ite: trust) {
            outDegree[ite[0] - 1]++;
            inDegree[ite[1] - 1]++;
        }
        for (int i = 0 ; i < n ; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};
