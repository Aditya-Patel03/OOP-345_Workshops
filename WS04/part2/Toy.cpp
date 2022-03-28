/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 13- Feb-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Toy.h"

using namespace std;
namespace sdds 
{
	void sdds::Toy::update(int items)
	{
		m_numOfItems = items;
	}
	
	Toy::Toy(const string& toy)
	{
		string str = toy;
		string t_orderID, t_name, numItems, t_price;

		t_orderID = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		t_name = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		numItems = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		t_price = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		t_name.erase(0, t_name.find_first_not_of(' '));
		t_name.erase(t_name.find_last_not_of(' ') + 1);

		m_orderID = stoi(t_orderID);
		m_name = t_name;
		m_numOfItems = stoi(numItems);
		m_price = stod(t_price);
	}
	
	ostream& operator<<(ostream& o, const Toy& t)
	{
		double sub = t.m_price * double(t.m_numOfItems);
		double tax = sub * t.m_tax;
		double totalprice = sub + tax;
// Displays Item subtotal and Total
		o << "Toy";
		o << setw(8) << t.m_orderID << ":";
		o << right << setw(18) << t.m_name;
		o << setw(3) << t.m_numOfItems;
		
		o << " items" << setw(8) << fixed << setprecision(2) << t.m_price;
		o << "/item  subtotal:" << setw(7) << fixed << setprecision(2) << sub;
		o << " tax:" << setw(6) << fixed << setprecision(2) << tax;
		o << " total:" << setw(7) << fixed << setprecision(2) << totalprice << endl;

		

		return o;
	}
}

