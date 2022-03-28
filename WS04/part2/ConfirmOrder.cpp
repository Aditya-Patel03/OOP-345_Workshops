/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 13- Feb-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "ConfirmOrder.h"
#include <iostream>

using namespace std;
namespace sdds {
	ConfirmOrder::~ConfirmOrder()
	{
		delete[] m_toy;
		m_toy = nullptr;
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& order)
	{
		if (this != &order)
		{
			m_num = order.m_num;
			delete[] m_toy;
			m_toy = new const Toy * [m_num];

			for (size_t i = 0; i < m_num; i++)
			{
				m_toy[i] = order.m_toy[i];
			}
		}

		return *this;
	}

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& order)
	{
		*this = order;
	}

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& order) noexcept
	{
		if (this != &order)
		{
			m_num = order.m_num;
			delete[] m_toy;
			m_toy = order.m_toy;

			order.m_toy = nullptr;
			order.m_num = 0;

		}

		return *this;
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder&& order) noexcept
	{
		*this = move(order);
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		bool inArray = false;

		for (size_t i = 0; i < m_num; i++) {
			if (m_toy[i] == &toy) {
				inArray = true;
			}
		}

		if (!inArray)
		{
			const Toy** temp = nullptr;//An attribute of type const sdds::Toy** representing the dynamically allocated array of pointers
			temp = new const Toy* [m_num + 1];

			for (size_t i = 0; i < m_num; i++)
			{
				temp[i] = m_toy[i];
			}

			temp[m_num] = &toy;
			m_num++;
			delete[] m_toy;
			m_toy = temp;
		}

		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		bool b = false;

		for (size_t i = 0; i < m_num; i++) {
			if (m_toy[i] == &toy) {
				b = true;
			}
		}

		if (b)
		{

			for (size_t i = 0; i < m_num; i++)
			{
				if (m_toy[i] == &toy) 
				{
					m_toy[i] = nullptr;
				}
			}

			m_num--;
		}

		return *this;
	}

	ostream& operator<<(ostream& o, const ConfirmOrder& order)
	{
		o << "--------------------------" << endl;
		o << "Confirmations to Send" << endl;
		o << "--------------------------" << endl;
		if (order.m_num == 0) {
			o << "There are no confirmations to send!\n";
		}
		else {
			for (size_t i = 0; i < order.m_num; i++) {
				if (order.m_toy[i] != nullptr) {
					o << *order.m_toy[i];
				}
			}
		}
		o<< "--------------------------\n";
		
		return o;
	}
}
