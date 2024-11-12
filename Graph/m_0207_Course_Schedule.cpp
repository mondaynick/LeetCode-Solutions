/*
  你必須休息總共numCourses門課，編號分別為0到numCourses-1，給定一個陣列prerequisites，
  其中prerequisites[i] = [a, b]代表必須要先修過b這門課才能往下修a這門課，如果有任一種方法
  能夠把所有課程修完，回傳true，否則回傳false

  利用topological sort，inDegree紀錄每個節點的入度數，neighbor紀錄每個節點的相鄰節點
  (1) 遍歷prerequisites，修改inDegree和neighbor
  (2) 將入度數為0的節點push到佇列中
  (3) 從佇列pop一個節點，透過其neighbor來修改inDegree
  (4) 若有相鄰節點的入度數為0，則將其push到佇列當中
  (5) 重複(3)和(4)，直到佇列為空，判斷已拜訪的節點數是否等於總課程數
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<set<int>> neighbor(numCourses);
        int count = 0;
        queue<int> deg0;

        for (vector<int> ite: prerequisites) {
            neighbor[ite[1]].insert(ite[0]);
            inDegree[ite[0]]++;
        }
        for (int i = 0 ; i < numCourses ; i++) {
            if (inDegree[i] == 0) {
                deg0.push(i);
            }
        }
        while (!deg0.empty()) {
            int temp = deg0.front();
            deg0.pop();
            count++;
            for (int ite: neighbor[temp]) {
                inDegree[ite]--;
                if (inDegree[ite] == 0) {
                    deg0.push(ite);
                }
            }
        }

        return count == numCourses;
    }
};