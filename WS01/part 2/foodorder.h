// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Michael Huang - 2021/11/28
/*
Name: Aditya Dharmesh Patel
Student ID : 143595205
email: adpatel31@myseneca.ca
Section:NCC
Date: 23-jan-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
	class FoodOrder
	{
		char m_custName[10];
		char m_foodDesc[25];
		double m_price;
		bool m_dailySpecial;
	public:
		void extractChar(std::istream& istr, char ch);
		FoodOrder();
		void read(std::istream&);
		void display()const;
	};
}

#endif