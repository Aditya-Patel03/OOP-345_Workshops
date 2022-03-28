/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 13- Mar-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <utility>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Filesystem.h"
#include "File.h"

std::string sdds::Filesystem::readNextInput(std::string input, unsigned int& p, bool spaces) {
    char c = input[p];
    std::string res = "";
    bool NoSpace = false;
    std::string spaceAdd = "";


    while(p < input.length()) {
        if (c == '\n' || c == '|' || c == '\r') {
            break;
        } else if (c != ' ' && !NoSpace) {
            NoSpace = true;
            res += c;
        } else if (NoSpace) {
            if (c == ' ') {
                if (spaces) {
                    spaceAdd += c;
                }
            } else {
                res += spaceAdd + c;
                spaceAdd = "";
            }

        }
        c = input[++p];
    }
    p++;

    return res;
}

std::vector<std::string> sdds::Filesystem::getFilePath(std::string p) {//p==path
    int pos = 0;
    std::vector<std::string> ps;//ps==paths

    for (unsigned int i = 0; i < p.length(); i++) {
        if (p[i] == '/') {
            int j = pos;//j set for previous position
            pos = i + 1;
            ps.emplace_back(p.substr(j, pos - j));
        }
    }

    return ps;
}

std::string sdds::Filesystem::getFileName(std::string path) {
    int pos = 0;
    std::string name = "";

    for (unsigned int i = 0; i < path.length(); i++) {
        if (path[i] == '/') {
            pos = i + 1;
        }
    }

    name = path.substr(pos, path.length());
    return name;
}


sdds::Filesystem::Filesystem(std::string filename, std::string root) {
    Directory* temp = new Directory(root);
    m_root = temp;
    m_current = temp;

    std::ifstream f(filename);
    std::string line, name, contents;
    std::vector<std::string> paths;
    unsigned int pos = 0;

    if (f.is_open()) {
        while (std::getline(f, line)) {
            name = readNextInput(line, pos, false);
            contents = readNextInput(line, pos, true);
            paths = getFilePath(name);
            name = getFileName(name);

            Directory* cur = m_root;
            std::vector<sdds::OpFlags> oflags;
            oflags.push_back(sdds::OpFlags::RECURSIVE);

            for (auto it = paths.begin(); it != paths.end(); it++) {
                Directory* dir = new Directory(*it);

                try {
                    *cur += dir;
                    cur = dir;
                } catch (...) {
                    delete dir;
                    cur = dynamic_cast<Directory*>(cur->find(*it));
                }
            }

            if (name.length() > 0) {
                File* file = new File(name, contents);
                try {      
                    *cur += file;
                } catch (...) {
                    delete file;
                }
            }
            // delete cur;
            pos = 0;
        }
    } else {
        delete temp;
        throw std::invalid_argument("Invalid file!");
    }
}

sdds::Filesystem::Filesystem(Filesystem&& f) {
    *this = std::move(f);
}

sdds::Filesystem& sdds::Filesystem::operator=(Filesystem&& f) {
    if (this == &f) {
        return *this;
    }

    std::swap(m_root, f.m_root);
    std::swap(m_current, f.m_current);
    return *this;
}

sdds::Filesystem& sdds::Filesystem::operator+=(Resource* r) {
    *m_current += r;
    return *this;
}

sdds::Directory* sdds::Filesystem::change_directory(const std::string& path) {
    if (path == "") {
        m_current = m_root;
    } else {
        Resource* r = m_current->find(path);
        if (r == nullptr) {
            throw std::invalid_argument("Cannot change directory! " + path + " was not found!");
        } else {
            m_current = dynamic_cast<Directory*>(r);
        }
    }
    return m_current;
}

sdds::Directory* sdds::Filesystem::get_current_directory() const {
    return m_current;
}

sdds::Filesystem::~Filesystem() {
   // delete[] m_root;
    delete m_root;
}