/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 13- Feb-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H

#include "Toy.h"

namespace sdds
{
	class ConfirmOrder {
	private:
		const Toy** m_toy{nullptr};
		size_t m_num{0};
	public:
		ConfirmOrder() = default;
		~ConfirmOrder();

		ConfirmOrder& operator=(const ConfirmOrder& order);
		ConfirmOrder(const ConfirmOrder& order);
		ConfirmOrder& operator=(ConfirmOrder&& order)noexcept;
		ConfirmOrder(ConfirmOrder&& order)noexcept;

		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& o, const ConfirmOrder& order);
	};
}
#endif // !SDDS_CONFIRMORDER_H

