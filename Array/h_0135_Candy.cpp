/*
  假設今天欲給 n 個小朋友發糖果，給定一個長度為 n 的陣列 ratings ，分別代表 n 個小朋友的 rating ，
  且發糖果必須滿足以下條件：
    (1) 每個小朋友至少需要獲得一顆糖果
    (2) 若一個小朋友的 rating 比其相鄰的小朋友還要高，他獲得的糖果必須比相鄰的小朋友多

  先從陣列 ratings 左邊遍歷到右邊，若目前小朋友的 rating 比左邊小朋友大，則發比左邊小朋友的糖果多一顆，
  再從陣列 ratings 右邊遍歷到左邊，若目前小朋友的 rating 比右邊小朋友大，則發比又逼小朋友的糖果多一顆，
  為了滿足以上條件，取兩者最大值後相加所有糖果數
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> leftToRight(len, 1);
        vector<int> rightToLeft(len, 1);
        for (int i = 1 ; i < len ; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                leftToRight[i] = leftToRight[i - 1] + 1;
            }
        }
        for (int i = len - 2 ; i >= 0 ; --i) {
            if (ratings[i] > ratings[i + 1]) {
                rightToLeft[i] = rightToLeft[i + 1] + 1;
            }
        }
        int res = 0;
        for (int i = 0 ; i < len ; ++i) {
            res += max(leftToRight[i], rightToLeft[i]);
        }
        return res;
    }
};
