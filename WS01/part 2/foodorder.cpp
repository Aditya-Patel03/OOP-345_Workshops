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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <string>
#include <cstring>
#include "foodorder.h"

using namespace std;

double g_taxrate;
double g_dailydiscount;

namespace sdds 
{

	FoodOrder::FoodOrder()
	{
		m_custName[0] = '\0';
		m_foodDesc[0] = '\0';
		m_price = -1;
		m_dailySpecial = false;
	}

	
	void FoodOrder::read(istream& istr)
	{
		char Name[10]{};
		char desc[25]{};
		double price = -1;
		char sp = '\0';

		if (istr.good())
		{
			
			istr.getline(Name, 10,',');
			istr.getline(desc, 25, ',');
			istr >> price;
			extractChar(istr, ',');
			istr >> sp;
			extractChar(istr, '\n');

			if (sp == 'Y')
			{
				m_dailySpecial = true;
			}
			else if (sp == 'N')
			{
				m_dailySpecial = false;
			}
			
				strcpy(m_custName, Name);
				strcpy(m_foodDesc, desc);

				m_price = price;
			
		}
	}
	
	void FoodOrder::display() const
	{

		static int x = 1;
		double taxPrice = (m_price * g_taxrate) + m_price;
		cout << left << setw(2) << x++ << ". ";
		if (m_custName[0] != '\0')
		{//Display Section
			cout << left << setw(10) << m_custName;
			cout << "|" << left << setw(25) << m_foodDesc;
			cout << "|" << left << setw(12) << setprecision(2) << fixed << taxPrice;
			cout << "|";

			if (m_dailySpecial == true)
			{
				cout << right << setw(13) << setprecision(2) << fixed << taxPrice - g_dailydiscount;
			}

		}
		else
		{
			cout << "No Order";
		}
		
		cout << endl;		
	}

	void FoodOrder::extractChar(istream& istr, char ch)
	{
		if (istr.peek() == ch)
		{
			istr.get();
		}
		else
		{
			istr.setstate(ios::failbit);
		}
	}
	
	
}