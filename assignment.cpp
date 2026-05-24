#include <iostream>
#include <string>

using namespace std;

// Function to calculate and display the student's result
void displayResult(string name, float m1, float m2, float m3) {
    float total = m1 + m2 + m3;
    float average = total / 3.0;
    
    cout << "\n--- Results for " << name << " ---" << endl;
    cout << "Total Marks: " << total << endl;
    cout << "Average: " << average << endl;
    
    // Check if the student passed or failed (Assuming 50 is the passing mark)
    if (average >= 50) {
        cout << "Status: Pass" << endl;
    } else {
        cout << "Status: Fail" << endl;
    }
}

int main() {
    string name;
    float m1, m2, m3;
    char choice;

    // Loop to allow input for multiple students
    do {
        cout << "\nEnter student name: ";
        cin >> name;
        
        cout << "Enter marks for 3 subjects: ";
        cin >> m1 >> m2 >> m3;
        
        // Call the function
        displayResult(name, m1, m2, m3);
        
        cout << "\nDo you want to enter another student? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');

    cout << "\nProgram exited successfully." << endl;
    
    return 0;
}