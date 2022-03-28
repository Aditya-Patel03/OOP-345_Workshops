/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 28-jan-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_

namespace sdds
{
	class ProteinDatabase
	{
	public:
		std::string* records = nullptr;
		long unsigned int len = 0;
long unsigned int index = 0;
		ProteinDatabase();
		~ProteinDatabase();

		ProteinDatabase(char* fname);
	
		size_t size();
		std::string operator[](size_t);

		ProteinDatabase(const ProteinDatabase& src);

		ProteinDatabase(ProteinDatabase&& src);

		ProteinDatabase& operator=(const ProteinDatabase&);
		ProteinDatabase& operator=(ProteinDatabase&&);



	

	};

}
#endif