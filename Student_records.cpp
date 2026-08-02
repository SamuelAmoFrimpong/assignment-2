#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(Student student) {
    double sum = 0;

    for (int i = 0; i < student.scores.size(); i++) {
        sum = sum + student.scores[i];
    }

    double average = sum / student.scores.size();
    return average;
}

void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    cin >> newStudent.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);

    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

void displayAllStudents(vector<Student>& students) {
    if (students.size() == 0) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < students.size(); i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;

        cout << "Scores: ";
        for (int j = 0; j < students[i].scores.size(); j++) {
            cout << students[i].scores[j] << " ";
        }
        cout << endl;

        double average = calculateAverage(students[i]);
        cout << "Average: " << average << endl;
        cout << "--------------------------------" << endl;
    }
}

void findAverageById(vector<Student>& students) {
    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == searchId) {
            double average = calculateAverage(students[i]);
            cout << fixed << setprecision(2);
            cout << students[i].name << "'s average score: " << average << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

void showMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<Student> students;
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            findAverageById(students);
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