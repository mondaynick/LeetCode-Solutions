/*
  一個m*n的整數陣列image代表了一張圖片，其中image[i][j]是圖片中一個像素的像素值，
  給定三個整數sr, sc和color，利用flood fill方式從image[sr][sc]開始把整張圖片塗
  成color，回傳新的圖片
  所謂flood fill是從起點開始，把該像素的上下左右四個像素中與起點相同者都一起塗成color

  利用bfs
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        int row = image.size(), col = image[0].size();
        queue<pair<int, int>> Q;
        int currColor = image[sr][sc];
        Q.push({sr, sc});
        while (!Q.empty()) {
            pair<int, int> temp = Q.front();
            Q.pop();
            image[temp.first][temp.second] = color;
            if (temp.first - 1 >= 0 && image[temp.first - 1][temp.second] == currColor)
                Q.push({temp.first - 1, temp.second});
            if (temp.second - 1 >= 0 && image[temp.first][temp.second - 1] == currColor)
                Q.push({temp.first, temp.second - 1});
            if (temp.first + 1 < row && image[temp.first + 1][temp.second] == currColor)
                Q.push({temp.first + 1, temp.second});
            if (temp.second + 1 < col && image[temp.first][temp.second + 1] == currColor)
                Q.push({temp.first, temp.second + 1});
        }
        return image;
    }
};
