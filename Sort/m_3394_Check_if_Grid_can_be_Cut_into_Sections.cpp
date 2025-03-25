/*
  給定一整數 n 和矩陣 rectangles ，其中 n 代表給定大小為 n x n 的二維平面，rectangles[i] = [xStart, yStart, xEnd, yEnd]
  分別代表每一塊矩形的 x 軸(和 y 軸)的左(和下)和右(和上)邊界 ，其中這些矩陣彼此之間不重疊，回傳是否存在兩條切線，範例如下：
  Ex 1.
  | - - - - - - - -
  | █   █   █   █ |  
  | - - - - - - - - - - ⬅
  | █   █ |
  |       |   - - - - -
  | █   █ |   | █   █ |
  | - - - - - - - - - - ⬅
  |   | █   █   █   █ |
  |   |               |       
  |   | █   █   █   █ |
  - - - - - - - - - - - 左圖存在兩條切線
  Ex 2.
          ⬇  ⬇
  |       - - -
  |       | █ |
  | - - - |   | - -
  | █   █ | █ | █ |
  | - - - |   |   |
  |       | █ | █ |
  | - -   |   |   |
  | █ |   | █ | █ |
  - - - - - - - - -     左圖存在兩條切線
  Ex 3.
              ⬇
  | - - - - - - - -
  | █   █ | █ | █ |
  |       |   |   |
  | █   █ | █ | █ |
  | - - - - - - - - ⬅
  |   | █   █ | █ |
  |   |       |   |
  |   | █   █ | █ |
  - - - - - - - - -     左圖不存在兩條切線

  對 x 軸左邊界坐標排序，找尋是否存在兩條邊界使得左側所有矩陣的右邊界均小於右側所有矩陣的左邊界
  對 y 軸下邊界坐標排序，找尋是否存在兩條邊界使得左側所有矩陣的下邊界均小於右側所有矩陣得上邊界
 */

class Solution {
private:
    static bool xCmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[2] < b[2];
        } else {
            return a[0] < b[0];
        }
    }

    static bool yCmp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[3] < b[3];
        } else {
            return a[1] < b[1];
        }
    }
    
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int count, rb;

        /* check if has two vertical cuts */
        sort(rectangles.begin(), rectangles.end(), xCmp);
        count = 0;
        rb = rectangles[0][2];
        for (vector<int> ite: rectangles) {
            if (ite[0] >= rb) ++count;
            rb = max(rb, ite[2]);
            if (count >= 2) break;
        }
        if (count >= 2) return true;

        /* check if has two horizontal cuts */
        sort(rectangles.begin(), rectangles.end(), yCmp);
        count = 0;
        rb = rectangles[0][3];
        for (vector<int> ite: rectangles) {
            if (ite[1] >= rb) ++count;
            rb = max(rb, ite[3]);
            if (count >= 2) break;
        }
        if (count >= 2) return true;
        return false;
    }
};
