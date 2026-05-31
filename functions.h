#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "LibraryBook.h"

// Define maximum capacity for the array
const int MAX_BOOKS = 100;

// Function prototypes from assignment sheet
void addBook(LibraryBook books[], int &bookCount);
void displayBooks(const LibraryBook books[], int bookCount);
void searchBook(const LibraryBook books[], int bookCount);
void borrowBookMenu(LibraryBook books[], int bookCount);
void returnBookMenu(LibraryBook books[], int bookCount);
void displayOverdueBooks(const LibraryBook books[], int bookCount);
void calculateTotalFines(const LibraryBook books[], int bookCount);

#endif