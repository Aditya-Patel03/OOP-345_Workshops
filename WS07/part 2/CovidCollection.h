/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 26- Mar-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
#include <iomanip>

namespace sdds {
	struct Covid {
		std::string country{};
		std::string city{};
		std::string variant{};
		std::string year{};
		size_t numberOfCases{};
		size_t m_deaths{};
	};
	class CovidCollection {
		std::vector<Covid> covid;
		std::string& trim(std::string& token);
	public:
		CovidCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(std::string str);
		void cleanList();
		bool inCollection(std::string str) const;
		std::list<Covid>getListForCountry(std::string str) const;
		std::list<Covid>getListForVariant(std::string str) const;

	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVIDCOLLECTION_H

