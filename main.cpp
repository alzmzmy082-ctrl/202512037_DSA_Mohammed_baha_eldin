#include <iostream>
#include "LibraryBook.h"
#include "Functions.h"

using namespace std;

int main() {
    LibraryBook bookList[MAX_BOOKS];
    int currentBookCount = 0;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "     Library Book Borrowing System       \n";
        cout << "=========================================\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book by ID\n";
        cout << "6. Display Overdue Books\n";
        cout << "7. Calculate Total Fines\n";
        cout << "8. Exit\n";
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(bookList, currentBookCount);
                break;
            case 2:
                displayBooks(bookList, currentBookCount);
                break;
            case 3:
                borrowBookMenu(bookList, currentBookCount);
                break;
            case 4:
                returnBookMenu(bookList, currentBookCount);
                break;
            case 5:
                searchBook(bookList, currentBookCount);
                break;
            case 6:
                displayOverdueBooks(bookList, currentBookCount);
                break;
            case 7:
                calculateTotalFines(bookList, currentBookCount);
                break;
            case 8:
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}