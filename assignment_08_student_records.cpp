// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// (instructions as given)
//

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

double calculateAverage(const Student& student) {
    if (student.scores.empty()) {
        return 0.0;
    }
    double sum = 0;
    for (size_t i = 0; i < student.scores.size(); i++) {
        sum += student.scores[i];
    }
    return sum / student.scores.size();
}

void addStudent(vector<Student>& students) {
    Student s;
    cin.ignore();
    cout << "Student name: ";
    getline(cin, s.name);
    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayAllStudents(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    for (size_t i = 0; i < students.size(); i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Scores: ";
        for (size_t j = 0; j < students[i].scores.size(); j++) {
            cout << students[i].scores[j];
            if (j != students[i].scores.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Average: " << calculateAverage(students[i]) << endl;
        cout << "--------------------------------" << endl;
    }
}

void calculateAverageForStudent(vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << fixed << setprecision(2);
            cout << students[i].name << "'s average score: "
                 << calculateAverage(students[i]) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

void printMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<Student> students;
    int choice;
    bool running = true;

    while (running) {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Error: Invalid choice. Please enter a number from 1 to 4." << endl;
        }

        cout << endl;
    }

    return 0;
}