/*
  設計一個任務管理系統，含有以下函式：
    (1) TaskManager(vector<vector<int>> tasks)
        將 tasks[i] = {userId_i, taskId_i, priority_i} 加入到任務管理系統裡面
    (2) int add(int userId, int taskId, int priority)
        將 {userId, taskId, priority} 加入到任務管理系統
    (3) void edit(int taskId, int newPriority)
        將 taskId 的 priority 設定成 newPriority
    (4) void rmv(int taskId)
        將 taskId 的任務刪除
    (5) int execTop()
        回傳 priority 最高的任務的 userId ，若有多個任務 priority 相同則回傳其 taskId 最大者
        之任務的 userId

  新增任務時記得排序，利用一個 hash table 紀錄指定的任務方便刪除
 */

class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int> task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskManager.insert({userId, taskId, priority});
        taskIdMp[taskId] = {userId, taskId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        vector<int> temp = taskIdMp[taskId];
        rmv(taskId);
        add(temp[0], taskId, newPriority);
    }
    
    void rmv(int taskId) {
        vector<int> temp = taskIdMp[taskId];
        taskManager.erase(temp);
        taskIdMp.erase(taskId);
    }
    
    int execTop() {
        if (taskManager.empty()) return -1;
        vector<int> temp = *taskManager.begin();
        rmv(temp[1]);
        return temp[0];
    }

private:
    set<vector<int>, decltype([](const vector<int> &left, const vector<int> &right){
        if (left[2] == right[2]) {
            return left[1] > right[1];
        } else {
            return left[2] > right[2];
        }
    })> taskManager;
    unordered_map<int, vector<int>> taskIdMp;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
