#include <bits/stdc++.h>
using namespace std;

struct Task {
    int userId;
    int taskId;
    int priority;
    Task() : userId(0), taskId(0), priority(0) {}
    Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}
};


struct TaskCmp {
    bool operator()(Task const &a, Task const &b) const {
        if (a.priority != b.priority)
            return a.priority > b.priority;
        return a.taskId > b.taskId;
    }
};

class TaskManager {
private:
    unordered_map<int, Task> taskMap;
    set<Task, TaskCmp> taskSet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &tk : tasks) {
            add(tk[0], tk[1], tk[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Task t(userId, taskId, priority);
        taskMap[taskId] = t;
        taskSet.insert(t);
    }
    
    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;
        Task old = it->second;
        taskSet.erase(old);
        Task updated(old.userId, taskId, newPriority);
        taskMap[taskId] = updated;
        taskSet.insert(updated);
    }
    
    void rmv(int taskId) {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end()) return;
        Task t = it->second;
        taskSet.erase(t);
        taskMap.erase(it);
    }
    
    int execTop() {
        if (taskSet.empty()) return -1;
        auto it = taskSet.begin();
        Task top = *it;
        taskSet.erase(it);
        taskMap.erase(top.taskId);
        return top.userId;
    }
};
