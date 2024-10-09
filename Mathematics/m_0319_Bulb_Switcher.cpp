/*
    給定有n盞燈，一開始都是關著，現在進行以下操作：
      第1輪操作把每一盞燈的開關按一下
      第2輪操作把每兩盞燈的開關按一下
      ...
      第n輪操作把每n盞燈的開關按一下
    求經過n輪操作後，有幾盞燈會是開的

    6 = 1 X 6 = 2 X 3
    代表第6盞燈在第1, 2, 3, 6輪皆會被按一次，共按了偶數次，故最後結果為關閉狀態
    16 = 1 X 16 = 2 X 8 = 4 X 4
    代表第16盞燈在第1, 2, 4, 8, 16輪皆會被按一次，共按了奇數次，故最後結果為開啟狀態
    可以得出結論，若n為平方數則第n盞最後為開啟狀態，故只要求1 ~ n共有多少個平方數
 */

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};