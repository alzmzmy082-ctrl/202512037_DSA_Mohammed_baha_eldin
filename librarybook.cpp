#include "LibraryBook.h"
#include <iostream>

// Default Constructor
LibraryBook::LibraryBook() {
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

// Parameterized Constructor
LibraryBook::LibraryBook(int id, std::string t, std::string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

// Destructor (Displays a message when object is destroyed as required)
LibraryBook::~LibraryBook() {
    if (bookID != 0) {
        std::cout << "[Destructor] Book ID " << bookID << " (\"" << title << "\") object destroyed.\n";
    }
}

// Getters & Setters Implementation
int LibraryBook::getBookID() const { return bookID; }
std::string LibraryBook::getTitle() const { return title; }
std::string LibraryBook::getAuthor() const { return author; }
std::string LibraryBook::getBorrowerName() const { return borrowerName; }
int LibraryBook::getDaysBorrowed() const { return daysBorrowed; }
bool LibraryBook::getIsBorrowed() const { return isBorrowed; }

void LibraryBook::setBorrowerName(std::string name) { borrowerName = name; }
void LibraryBook::setDaysBorrowed(int days) { daysBorrowed = days; }
void LibraryBook::setIsBorrowed(bool status) { isBorrowed = status; }