#include <iostream>
#include <queue>
#include <vector>
#include <thread>
#include <functional>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

struct Task {
    int priority;
    function<void()> func;
    
    bool operator<(const Task &other) const {
        return priority < other.priority; // Higher priority tasks will be processed first
    }
};

class TaskScheduler {
private:
    priority_queue<Task> taskQueue;
    mutex mtx;
    condition_variable cv;
    bool stop;
    
public:
    TaskScheduler() : stop(false) {}
    
    void addTask(int priority, function<void()> func) {
        lock_guard<mutex> lock(mtx);
        taskQueue.push({priority, func});
        cv.notify_one();
    }
    
    void run() {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return !taskQueue.empty() || stop; });
            
            if (stop && taskQueue.empty()) return;
            
            Task task = taskQueue.top();
            taskQueue.pop();
            lock.unlock();
            
            task.func();
        }
    }
    
    void shutdown() {
        lock_guard<mutex> lock(mtx);
        stop = true;
        cv.notify_all();
    }
};

int main() {
    TaskScheduler scheduler;
    thread schedulerThread(&TaskScheduler::run, &scheduler);
    
    scheduler.addTask(1, [] { cout << "Low priority task executed" << endl; });
    scheduler.addTask(3, [] { cout << "High priority task executed" << endl; });
    scheduler.addTask(2, [] { cout << "Medium priority task executed" << endl; });
    
    this_thread::sleep_for(chrono::seconds(2)); // Allow tasks to execute
    scheduler.shutdown();
    schedulerThread.join();
    
    return 0;
}
