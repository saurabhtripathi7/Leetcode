class TaskManager {
public:
    unordered_map<int,int>taskId_userId;
    unordered_map<int,int>taskId_priority;
    priority_queue<pair<int,int>>priority_taskId;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0;i<tasks.size();i++){
            add(tasks[i][0],tasks[i][1],tasks[i][2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        priority_taskId.push({priority,taskId});
        taskId_userId[taskId] = userId;
        taskId_priority[taskId]  = priority;
    }
    
    void edit(int taskId, int newPriority) {
        taskId_priority[taskId] = newPriority;
        priority_taskId.push({newPriority,taskId});

    }
    
    void rmv(int taskId) {
        taskId_priority[taskId] = -1;
    }
    
    int execTop() {
        while(!priority_taskId.empty()){
            auto[priority,taskId] = priority_taskId.top();
            priority_taskId.pop();

            if(priority==taskId_priority[taskId])
            {
                taskId_priority[taskId] = -1;
                return taskId_userId[taskId];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
