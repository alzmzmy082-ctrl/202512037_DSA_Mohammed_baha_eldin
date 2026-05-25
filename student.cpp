#include "student.h"

Student students[100];
int countStudents = 0;

void addStudent() {
    cout << "Enter Student ID: ";
    cin >> students[countStudents].id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, students[countStudents].name);

    cout << "Enter Age: ";
    cin >> students[countStudents].age;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, students[countStudents].course);

    countStudents++;

    cout << "Student Added Successfully.\n";
}

void displayStudents() {
    if (countStudents == 0) {
        cout << "No Students Found.\n";
        return;
    }

    for (int i = 0; i < countStudents; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
    }
}

void searchStudent() {
    int id;
    cout << "Enter Student ID to Search: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++) {
        if (students[i].id == id) {
            cout << "Student Found:\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;
            return;
        }
    }

    cout << "Student Not Found.\n";
}

void updateStudent() {
    int id;
    cout << "Enter Student ID to Update: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++) {
        if (students[i].id == id) {

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, students[i].name);

            cout << "Enter New Age: ";
            cin >> students[i].age;

            cin.ignore();

            cout << "Enter New Course: ";
            getline(cin, students[i].course);

            cout << "Student Updated Successfully.\n";
            return;
        }
    }

    cout << "Student Not Found.\n";
}

void deleteStudent() {
    int id;
    cout << "Enter Student ID to Delete: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++) {
        if (students[i].id == id) {

            for (int j = i; j < countStudents - 1; j++) {
                students[j] = students[j + 1];
            }

            countStudents--;

            cout << "Student Deleted Successfully.\n";
            return;
        }
    }

    cout << "Student Not Found.\n";
}