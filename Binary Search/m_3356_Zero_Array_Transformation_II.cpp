/*
  給定一個陣列 nums 和二維矩陣 queries，其中 queries[i] = [li, ri, vi]，定義：
    (1) [li, ri, vi] 代表索引從 li 到 ri 的數值最多可以減少 vi
    (2) 索引內的數值可以獨立減少，不一定所有都要減少 vi
  遍歷 queries ，回傳遍歷到索引 k 使得 nums 所有元素變為 0 的最小索引 k (1-indexed)

  利用 binary search 搭配 prefix sum
 */

class Solution {
private:
    bool check(vector<int> nums, vector<vector<int>>& queries, int mid) {
        int nlen = nums.size();
        vector<int> cnt(nlen + 1, 0);
        for (int i = 0 ; i < mid ; ++i) {
            cnt[queries[i][0]] += queries[i][2];
            cnt[queries[i][1] + 1] -= queries[i][2];
        }
        int sum = 0;
        for (int i = 0 ; i < nlen ; i++) {
            sum += cnt[i];
            if (sum < nums[i]) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int nlen = nums.size(), qlen = queries.size();
        for (int i = 0 ; i <= nlen ; ++i) {
            if (i == nlen) return 0;
            else if (nums[i] != 0) break;
        }
        if (!check(nums, queries, qlen)) return -1;
        int left = -1, right = qlen;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(nums, queries, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
