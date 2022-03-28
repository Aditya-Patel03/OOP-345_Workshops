/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 13- Mar-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include <string>
#include "Resource.h"
#include "Flags.h"

namespace sdds {
    class File : public Resource {
        
        public:
        std::string m_contents;
        File(std::string filename, std::string contents = "");
        void update_parent_path(const std::string&) override;
        NodeType type() const override;
        std::string path() const override;
        std::string name() const override;
        int count() const override;
        size_t size() const override;
    };
};

#endif