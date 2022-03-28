/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 13- Mar-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H

#include <string>
#include <vector>
#include "Resource.h"
#include "Flags.h"


namespace sdds {
    class Directory : public Resource {
        std::vector<Resource*> m_contents;

        public:
        Directory(std::string dirname);
        void update_parent_path(const std::string&) override;
        NodeType type() const override;
        std::string path() const override;
        std::string name() const override;
        int count() const override;
        size_t size() const override;
        Directory& operator+=(Resource*);
        Resource* find(const std::string&, const std::vector<OpFlags>& flag = {});
        ~Directory();
        Directory& operator=(const Directory&) = delete;
        Directory& operator=(Directory&&) = delete;
        void remove(const std::string& path, const std::vector<OpFlags>& flag = {});
        void display(std::ostream&, const std::vector<FormatFlags>& flag = {}) const;
    };
};

#endif