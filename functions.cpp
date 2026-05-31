#include "Functions.h"
#include <iostream>

using namespace std;

// 1. Add New Book
void addBook(LibraryBook books[], int &bookCount) {
    if (bookCount >= MAX_BOOKS) {
        cout << "Database full! Cannot add more books.\n";
        return;
    }
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore(); // Clear buffer before reading strings
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);

    books[bookCount] = LibraryBook(id, title, author);
    bookCount++;
    cout << "Book added successfully!\n";
}

// 2. Display All Books
void displayBooks(const LibraryBook books[], int bookCount) {
    if (bookCount == 0) {
        cout << "No books available in the library system.\n";
        return;
    }
    cout << "\n--- Library Catalog ---\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "ID: " << books[i].getBookID() 
             << " | Title: " << books[i].getTitle() 
             << " | Author: " << books[i].getAuthor();
        if (books[i].getIsBorrowed()) {
            cout << " | [Borrowed by: " << books[i].getBorrowerName() 
                 << ", Days: " << books[i].getDaysBorrowed() << "]";
        } else {
            cout << " | [Available]";
        }
        cout << endl;
    }
}

// 5. Search Book by ID
void searchBook(const LibraryBook books[], int bookCount) {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            cout << "Book Found:\n";
            cout << "Title: " << books[i].getTitle() << "\nAuthor: " << books[i].getAuthor() << endl;
            return;
        }
    }
    cout << "Book not found.\n";
}

// 3. Borrow Book
void borrowBookMenu(LibraryBook books[], int bookCount) {
    int id;
    cout << "Enter Book ID to borrow: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (books[i].getIsBorrowed()) {
                cout << "Sorry, this book is already borrowed by " << books[i].getBorrowerName() << ".\n";
                return;
            }
            string name;
            int days;
            cin.ignore();
            cout << "Enter Borrower Name: ";
            getline(cin, name);
            cout << "Enter Number of Days to Borrow: ";
            cin >> days;

            books[i].setBorrowerName(name);
            books[i].setDaysBorrowed(days);
            books[i].setIsBorrowed(true);
            cout << "Book successfully borrowed!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// 4. Return Book
void returnBookMenu(LibraryBook books[], int bookCount) {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (!books[i].getIsBorrowed()) {
                cout << "This book is already in the library (Not borrowed).\n";
                return;
            }
            books[i].setBorrowerName("");
            books[i].setDaysBorrowed(0);
            books[i].setIsBorrowed(false);
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// 6. Display Overdue Books (Assuming standard borrow limit is 7 days)
void displayOverdueBooks(const LibraryBook books[], int bookCount) {
    bool found = false;
    cout << "\n--- Overdue Books (Borrowed for more than 7 days) ---\n";
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getIsBorrowed() && books[i].getDaysBorrowed() > 7) {
            cout << "ID: " << books[i].getBookID() 
                 << " | Title: " << books[i].getTitle() 
                 << " | Borrower: " << books[i].getBorrowerName() 
                 << " | Total Days: " << books[i].getDaysBorrowed() 
                 << " (" << (books[i].getDaysBorrowed() - 7) << " days late)\n";
            found = true;
        }
    }
    if (!found) cout << "No overdue books at the moment.\n";
}

// 7. Calculate Total Fines (Assuming fine rate is 500 RWF per overdue day)
void calculateTotalFines(const LibraryBook books[], int bookCount) {
    double totalFines = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getIsBorrowed() && books[i].getDaysBorrowed() > 7) {
            int overdueDays = books[i].getDaysBorrowed() - 7;
            totalFines += (overdueDays * 500); 
        }
    }
    cout << "Total Fines for all overdue books: " << totalFines << " RWF\n";
}