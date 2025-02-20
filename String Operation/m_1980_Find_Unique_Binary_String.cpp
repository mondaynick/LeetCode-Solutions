/*
  給定長度為 n 的陣列 nums ，其中陣列中每個二元字串的長度皆為 n ，回傳其長度為 n 的二元字串且不出現在 nums 中

  長度為 n 的陣列且每個子串皆為 n 的情況下，只要任意找一個位元與其相反，組成的位元串必定不會跟該字串相同
 */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int len = nums.size();
        string res;
        for (int i = 0 ; i < len ; i++) {
            res += (nums[i][i] == '0') ? '1' : '0';
        }
        return res;
    }
};
