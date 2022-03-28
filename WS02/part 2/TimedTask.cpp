/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 28-jan-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
#include "TimedTask.h"

namespace sdds {

	void TimedTask::startClock()
	{
		startTime = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock()
	{
		endTime = std::chrono::steady_clock::now();
	}

	ostream& operator<<(std::ostream& os, const TimedTask& tasks) {
		// Display Execution Part
		os << "--------------------------\n" << "Execution Times:\n--------------------------\n";
		for (int i = 0; i < tasks.m_records; i++) {
			os << std::setw(21) << std::left << tasks.m_task[i].taskName << " ";
			os << std::setw(13) << std::right << tasks.m_task[i].duration.count() << " " << tasks.m_task[i].unit << "\n";
		}
		return os << "--------------------------\n";
	}

	void TimedTask::addTask(std::string name){

		m_task[m_records].taskName = name;
		m_task[m_records].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
		m_task[m_records].unit = "nanoseconds";

		m_records += 1;
	}



}