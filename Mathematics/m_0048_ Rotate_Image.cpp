/*
  給定n * n的陣列，將其順時針旋轉90度

  將陣列分為好幾圈，從最外圈往最內圈遍歷，交換如下
  A A A B
  D     B
  D     B
  D C C C
  將A放到B，將B放到C，將C放到D，將D放到A，
  其中layer代表從外面數進來第幾圈，offset代表從該節點往旁邊偏移：
    左上角：[layer][layer + offset]
    左下角：[len - 1 - layer - offset][layer]
    右上角：[layer + offset][len - 1 - layer]
    右下角：[len - 1 - layer][len - 1 - layer - offset]
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for (int layer = 0 ; layer < len / 2 ; layer++) {
            for (int offset = 0 ; offset < len - layer - 1 - layer ; offset++) {
                /*
                    left up -> [layer][layer + offset]
                    left down -> [len - 1 - layer - offset][layer]
                    right up -> [layer + offset][len - 1 - layer]
                    right down -> [len - 1 - layer][len - 1 - layer - offset]
                */
                int temp = matrix[layer][layer + offset];
                matrix[layer][layer + offset] = matrix[len - 1 - layer - offset][layer];
                matrix[len - 1 - layer - offset][layer] = matrix[len - 1 - layer][len - 1 - layer - offset];
                matrix[len - 1 - layer][len - 1 - layer - offset] = matrix[layer + offset][len - 1 - layer];
                matrix[layer + offset][len - 1 - layer] = temp;
            }
        }
    }
};
