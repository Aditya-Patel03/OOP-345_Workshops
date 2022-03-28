/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 13- Mar-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H
//#include "Flags.h"
#include "Resource.h"
#include "Directory.h"

namespace sdds {
    class Filesystem {
        Directory* m_root;
        Directory* m_current;
        std::string readNextInput(std::string input, unsigned int& pos, bool spaces = false);
        std::vector<std::string> getFilePath(std::string);
        std::string getFileName(std::string);

        public:
        Filesystem(std::string filename, std::string root = "");
        Filesystem(const Filesystem&) = delete;
        Filesystem(Filesystem&&);
        Filesystem& operator=(const Filesystem&) = delete;
        Filesystem& operator=(Filesystem&&);
        Filesystem& operator+=(Resource*);
        Directory* change_directory(const std::string& path = "");
        Directory* get_current_directory() const;
        ~Filesystem();
    };
};

#endif