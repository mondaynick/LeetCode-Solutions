/*
  給定一個陣列 arr 和三個整數分別為 a, b, c ，求陣列中符合以下條件的子陣列共有多少個
    1. 子陣列長度為3 ，子陣列為subarr[3] = [nums[i], nums[j], nums[k]]
    2. 0 <= i < j < k <= arr.size()
    3. |nums[i] - nums[j]| <= a
    4. |nums[j] - nums[k]| <= b
    5. |nums[i] - nums[k]| <= c

  列出所有可能性，一一判斷符合條件的數量
 */

class Solution {
private:
    void handler(int &res, const vector<int> &arr, int a, int b, int c, vector<int> temp, int start) {
        if (temp.size() == 3) {
            if ((abs(temp[0] - temp[1]) <= a) && (abs(temp[1] - temp[2]) <= b) && (abs(temp[0] - temp[2]) <= c)) {
                res++;
            }
            return;
        }
        for (int i = start ; i < arr.size() ; ++i) {
            temp.push_back(arr[i]);
            handler(res, arr, a, b, c, temp, i + 1);
            temp.pop_back();
        }
    }
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int res = 0;
        vector<int> temp;
        handler(res, arr, a, b, c, temp, 0);
        return res;
    }
};
