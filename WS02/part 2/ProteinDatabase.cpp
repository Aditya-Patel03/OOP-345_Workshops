/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 28-jan-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include<string>
using namespace std;

#include "ProteinDatabase.h"

namespace sdds {

	ProteinDatabase::ProteinDatabase()
	{}

	ProteinDatabase::ProteinDatabase(char* f_name)
	{
		len = 0;
		records = nullptr;
		ifstream fname(f_name);
		if (!fname)
		{
			return;
		}
		string line, name;
		while (std::getline(fname,line).good()){
			if (line[0] == '>'){
				len++;
			}
		}
		fname.clear();
		fname.seekg(ios::beg);	
		records = new string[len];
		line.clear();
		int i = -1;
		while (getline(fname,line).good()){
			if (line[0] == '>'){
				++i;
				name = line.substr(1);
			}
			else if (!name.empty()){
				records[i] += line;
			}
		}
	}


	ProteinDatabase::ProteinDatabase(ProteinDatabase&& old) {
		*this = std::move(old);
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& old){
        *this = old;
	}


	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src){
		if (this != &src) {

			delete[] records;
			records = nullptr;

			records = src.records;
			src.records = nullptr;
			len = src.len;
			src.len = 0;
		}
		return *this;
	}

	
	size_t ProteinDatabase::size() {
		return len;
	}

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src){
        if (this != &src) {
            delete[] records;
            len = src.len;

            records = new string[len]{};

            for (long unsigned int i = 0; i < len; i++){
                records[i] = src.records[i];
            }
        }

        return *this;
    }


	std::string ProteinDatabase::operator[](size_t index) {

		if (index < len) {

			return records[index];
		}
		return "";
	}

	ProteinDatabase::~ProteinDatabase() {
		delete[] records;
	}
}