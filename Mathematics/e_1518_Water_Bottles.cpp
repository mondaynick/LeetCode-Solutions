/*
 給定兩個整數 numBottles 和 numExchange ，其中 numBottles 代表剛開始有幾罐滿的水，而 numExchange 代表多少個
 空瓶子可以換一罐新的水，回傳總共可以喝幾罐完整的水

 根據定義求解
 */

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            ans += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }
        return ans;
    }
};
