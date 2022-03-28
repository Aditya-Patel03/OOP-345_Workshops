/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 13- Feb-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <string>

namespace sdds {
	class Toy
	{
		unsigned int m_orderID;
		std::string m_name;
		int m_numOfItems;
		double m_price;
		double m_tax = 0.13;

	public:
		Toy() = default;
		void update(int numItems);
		Toy(const std::string& toy);
		friend std::ostream& operator<<(std::ostream& o, const Toy& toy);
	};
}
#endif // !SDDS_TOY_H
