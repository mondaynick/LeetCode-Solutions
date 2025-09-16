/*
  給定一個陣列 nums ，若陣列存在相鄰兩個元素沒有互質，將其刪除並且替換成其最小公倍數，
  直到不存在相鄰兩個元素沒有互質，回傳該陣列

  先利用堆疊，每次比較當前元素和堆疊頂端的元素是否沒有互質，若沒有互質則計算兩者最小公倍
  數為何，可以利用 lcm(a, b) = a * b / gcd(a, b) 求得，有以下兩點要注意：
  (1) 因為每次替換成最小公倍數時，可能會與更前面的數字有非互質的關係，所以要確保與前面已
      經互質才可以新增下一個數字
  (2) 因為 a * b 可能會導致溢位，所以在計算最小公倍數時可以分兩步驟先進行除法再進行乘法
 */

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> stk;
        for (int num : nums) {
            int curr = num;
            while (!stk.empty()) {
                int gcdNum = gcd(curr, stk.top());
                if (gcd(curr, gcdNum) == 1) break;
                curr /= gcdNum;
                curr *= stk.top();
                stk.pop();
            }
            stk.push(curr);
        }
        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// a * b = gcd(a, b) * lcm(a, b)
// lcm(a, b) = a * b / gcd(a, b)
