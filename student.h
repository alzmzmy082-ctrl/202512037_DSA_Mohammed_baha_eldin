#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string id;
    std::string name;
    int age;
};


void saveStudentsToCSV(const std::vector<Student>& students, const std::string& filename);

#endif 