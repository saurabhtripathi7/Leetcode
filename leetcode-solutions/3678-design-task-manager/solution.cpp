class TaskManager {
    unordered_map<int, pair<int, int>> taskMap; // taskId -> (userId, priority)
    priority_queue<tuple<int, int, int>> maxHeap; // (priority, taskId, userId)

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskMap[taskId] = {userId, priority};
            maxHeap.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        maxHeap.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        if (taskMap.find(taskId) != taskMap.end()) {
            int userId = taskMap[taskId].first;
            taskMap[taskId].second = newPriority;
            maxHeap.push({newPriority, taskId, userId});
        }
    }

    void rmv(int taskId) {
        taskMap.erase(taskId);
    }

    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, taskId, userId] = maxHeap.top();
            maxHeap.pop();
            if (taskMap.find(taskId) != taskMap.end() && taskMap[taskId].second == priority) {
                taskMap.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};

