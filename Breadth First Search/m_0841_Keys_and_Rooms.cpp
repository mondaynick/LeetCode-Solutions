/*
  總共有N個未上鎖的房間，而你從編號0的房間room0出發(只有room0未上鎖)，房間被依序編號為0, 1, 2, ..., N-1，
  且每個房間中有若干個鑰匙可以用來進入其他房間，rooms[i][j]代表房間room i有一把可以開啟房間room j的鑰匙，打
  開其他房間並進入之後，隨時可以回到之前進入過的房間，若能進入所有房間則回傳true，反之則回傳false

  
 */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        queue<int> Q;
        int count = 0;
        Q.push(0);
        while (!Q.empty()) {
            int temp = Q.front();
            cout << temp << endl;
            Q.pop();
            visited.insert(temp);
            for (int ite: rooms[temp]) {
                if (!visited.count(ite)) {
                    Q.push(ite);
                }
            }
        }
        return visited.size() == rooms.size();
    }
};
