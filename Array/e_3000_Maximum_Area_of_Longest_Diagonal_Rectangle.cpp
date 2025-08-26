/*
  給定一個二維陣列 dimensions ，其中 dimensions[i] = [li, wi] 的 li 和 wi 分別代表第 i 個三角形的
  長度和寬度，回傳具有最大長度之對角線必且具有最大矩形面積之三角形的矩形面積

  根據題意遍歷 dimensions ，要注意相同對角線不代表矩形面積會相同
 */

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0, dlen = 0;
        for(vector<int> dim : dimensions) {
            int tArea = dim[0] * dim[1];
            int tDlen = dim[0] * dim[0] + dim[1] * dim[1];
            if (tDlen > dlen || (tDlen == dlen && tArea > area)) {
                area = tArea;
                dlen = tDlen;
            }
        }
        return area;
    }
};
