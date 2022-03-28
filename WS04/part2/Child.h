/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 2- Mar-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H

#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {
	class Child
	{
	private:
		Toy* toy{};
		size_t m_num;
		std::string m_childName;
		int m_age;
	public:
		Child();
		Child& operator=(const Child& child);
		Child(const Child& child);
		Child(Child&& child) ;
		Child& operator=(Child&& child) ;
		~Child();

		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& o, const Child& child);
	};
}
#endif // !SDDS_CHILD_H
