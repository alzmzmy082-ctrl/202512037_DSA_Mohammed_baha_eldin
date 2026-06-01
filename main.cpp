#include <iostream>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

int main() {
    int numberOfStudents;
    vector<Student> students;

    cout << "=== Student Data Entry ===" << endl;
    cout << "Enter the number of students to add: ";
    cin >> numberOfStudents;
    cin.ignore(); 

    
    for (int i = 0; i < numberOfStudents; i++) {
        Student s;
        cout << "\n--- Student " << (i + 1) << " ---" << endl;
        
        cout << "Enter Student ID (e.g., 202312051): ";
        getline(cin, s.id);
        
        cout << "Enter Student Name: ";
        getline(cin, s.name);
        
        cout << "Enter Student Age: ";
        cin >> s.age;
        cin.ignore(); 

        students.push_back(s); 
    }

    
    saveStudentsToCSV(students, "student.txt");

    cout << "\n=============================================" << endl;
    cout << "Data has been successfully saved to 'student.txt'" << endl;
    cout << "=============================================" << endl;

    return 0;
}