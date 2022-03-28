/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 28-jan-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include<chrono>
#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_

namespace sdds{
	const int MAX = 10;
	class TimedTask{
	public:
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct Task{
			std::string taskName;
			std::string unit;
			std::chrono::steady_clock::duration duration;
		};

		Task m_task[MAX];
		int m_records = 0;
		
		friend std::ostream& operator<<(std::ostream& os, const TimedTask& tasks);
		void startClock();
		void stopClock();
		void addTask(std::string name);

	
	};
}



#endif