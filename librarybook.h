#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <string>

class LibraryBook {
private:
    int bookID;
    std::string title;
    std::string author;
    std::string borrowerName;
    int daysBorrowed;
    bool isBorrowed;

public:
    // Constructors & Destructor
    LibraryBook();
    LibraryBook(int id, std::string t, std::string a);
    ~LibraryBook();

    // Getters and Setters
    int getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getBorrowerName() const;
    int getDaysBorrowed() const;
    bool getIsBorrowed() const;

    void setBorrowerName(std::string name);
    void setDaysBorrowed(int days);
    void setIsBorrowed(bool status);
};

#endif