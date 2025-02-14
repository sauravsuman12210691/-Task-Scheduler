
---

# **Task Scheduler**  
A lightweight job scheduler implemented in **C++** using **multithreading** and **priority queues**.

## **Features**  
✔️ Supports **scheduling tasks** with different priorities  
✔️ Uses **multithreading** for concurrent execution  
✔️ Implements **synchronization mechanisms** (mutex, condition variables)  
✔️ Provides **dynamic task addition and cancellation**  
✔️ Optimized using **priority queues** for efficient task execution  

## **Technologies Used**  
- **C++ (C++11/14/17)**  
- **Multithreading (std::thread, std::mutex, std::condition_variable)**  
- **Priority Queues (std::priority_queue)**  

## **How It Works**  
1. Tasks are added with a priority and execution time.  
2. A worker thread picks the highest-priority task and executes it.  
3. Tasks can be dynamically added or removed.  

## **Installation & Usage**  
1. Clone the repository:  
   ```sh
   git clone https://github.com/yourusername/task-scheduler.git
   cd task-scheduler
   ```
2. Compile the project:  
   ```sh
   g++ -std=c++17 -pthread task_scheduler.cpp -o scheduler
   ```
3. Run the executable:  
   ```sh
   ./scheduler
   ```

## **Example Usage**  
```cpp
TaskScheduler scheduler;
scheduler.addTask([] { std::cout << "Task 1 executed\n"; }, 1);
scheduler.addTask([] { std::cout << "Task 2 executed\n"; }, 2);
scheduler.run();
```

## **Future Enhancements**  
- ⏳ **Periodic Tasks** (Run tasks at fixed intervals)  
- ❌ **Task Cancellation** (Remove tasks dynamically)  
- 🚀 **Thread Pool Implementation** for efficiency  

---
