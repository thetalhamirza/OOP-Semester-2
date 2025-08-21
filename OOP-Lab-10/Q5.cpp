#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

const std::string FILE_NAME = "todo.txt";


struct Task {
    bool done;
    std::string description;
};


std::vector<Task> loadTasks() {
    std::vector<Task> tasks;
    std::ifstream file(FILE_NAME);
    std::string line;

    while (getline(file, line)) {
        if (line.size() < 4) continue; // Skip malformed lines
        bool done = (line[1] == '1');
        std::string desc = line.substr(4);
        Task task;
        task.done = done;
        task.description = desc;
        tasks.push_back(task);
    }
    return tasks;
}


void saveTasks(const std::vector<Task>& tasks) {
    std::ofstream file(FILE_NAME);
    for (const auto& task : tasks) {
        file << "[" << (task.done ? "1" : "0") << "] " << task.description << "\n";
    }
}



void addTask() {
    std::string desc;
    std::cin.ignore(); // Clear newline from input
    std::cout << "Enter task description: ";
    getline(std::cin, desc);
    std::ofstream file(FILE_NAME, std::ios::app);
    file << "[0] " << desc << "\n";
    std::cout << "Task added.\n";
}


void viewTasks() {
    auto tasks = loadTasks();
    if (tasks.empty()) {
        std::cout << "No tasks found.\n";
        return;
    }
    std::cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". [" << (tasks[i].done ? "X" : " ") << "] " << tasks[i].description << "\n";
    }
}


void markTaskDone() {
    auto tasks = loadTasks();
    viewTasks();
    if (tasks.empty()) return;

    int index;
    std::cout << "Enter task number to mark as done: ";
    std::cin >> index;

    if (index < 1 || index > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].done = true;
    saveTasks(tasks);
    std::cout << "Task marked as done.\n";
}

int main() {
    int choice;
    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Done\n4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskDone(); break;
            case 4: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
