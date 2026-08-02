#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addTask(vector<string>& tasks) {
    string task;

    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);

    tasks.push_back(task);

    cout << "Task added: \"" << task << "\"" << endl;
}

void viewTasks(vector<string>& tasks) {
    if (tasks.size() == 0) {
        cout << "Your task list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;

    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.size() == 0) {
        cout << "Your task list is empty." << endl;
        return;
    }

    viewTasks(tasks);

    int taskNum;
    cout << "Enter task number to delete: ";
    cin >> taskNum;

    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removedTask = tasks[taskNum - 1];
    tasks.erase(tasks.begin() + (taskNum - 1));

    cout << "Task \"" << removedTask << "\" has been removed." << endl;
}

void showMenu() {
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<string> tasks;
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            running = false;
        } else {
            cout << "Error: Invalid choice. Please enter a number from 1 to 4." << endl;
        }

        cout << endl;
    }

    return 0;
}