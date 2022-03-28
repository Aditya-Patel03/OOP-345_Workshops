/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 13- Feb-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Child.h"
using namespace std;
namespace sdds {
	Child::Child()
	{
		delete[] toy;
		toy = nullptr;

		m_num = 0;
		m_childName = "";
		m_age = 0;
	}
	
	Child& Child::operator=(const Child& child)
	{
		if (this != &child)
		{
			m_num = child.m_num;
			m_childName = child.m_childName;
			m_age = child.m_age;

			delete[] toy;
			toy = new Toy[m_num];

			for (size_t i = 0; i < m_num; i++)
			{
				toy[i] = child.toy[i];
			}
		}

		return *this;
	}

	Child::Child(const Child& child)
	{
		*this = child;
	}
	
	Child::Child(Child&& child) 
	{
		*this = move(child);
	}
	Child& Child::operator=(Child&& child) 
	{
		if (this != &child)
		{
			m_num = child.m_num;
			m_childName = child.m_childName;
			m_age = child.m_age;

			delete[] toy;
			toy = child.toy;

			child.toy = nullptr;
			child.m_num = 0;
			child.m_childName = "";
			child.m_age = 0;

		}

		return *this;
	}

	Child::~Child()
	{
		delete[] toy;
		toy = nullptr;
	}

	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		toy = new Toy[count];
		m_childName = name;
		m_age = age;
		m_num = count;

		for (size_t i = 0; i < count; i++)
		{
			toy[i] = *toys[i];
		}
	}
	size_t Child::size() const
	{
		return m_num;
	}
	
	ostream& operator<<(ostream& o, const Child& child)
	{
		static size_t CALL_CNT;
		++CALL_CNT;
		o << "--------------------------\n"
			<< "Child " << CALL_CNT << ": " << child.m_childName << " " << child.m_age << " years old:" << endl;
			o << "--------------------------\n";

		if (child.m_num == 0) {
			o << "This child has no toys!" << endl;
		}
		else {
			for (size_t i = 0; i < child.m_num; i++) {
				o << child.toy[i];
			}
		}
		o << "--------------------------\n";
		return o;
	}
}

