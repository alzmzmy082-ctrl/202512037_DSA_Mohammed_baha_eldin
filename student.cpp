#include "student.h"
#include <fstream>
#include <iostream>

void saveStudentsToCSV(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error: Could not create or open the file!" << std::endl;
        return;
    }

    
    for (const auto& s : students) {
        outFile << s.id << "," << s.name << "," << s.age << "\n";
    }

    outFile.close();
}