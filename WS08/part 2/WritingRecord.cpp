/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 26- Mar-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
    GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
        GeneratingList<EmployeeWage> activeEmp;
        for (size_t i = 0; i < emp.size(); i++) {
            for (size_t j = 0; j < sal.size(); j++) {
                if (emp[i].id == sal[j].id) {
                    EmployeeWage* temp = new EmployeeWage(emp[i].name, sal[j].salary);
                    try {
                        temp->rangeValidator();
                    }
                    catch (...) {
                        delete temp;
                        throw;
                    }
                    if (!activeEmp.isValidSIN(emp[i].id)) {
                        throw std::string{ " " };
                    };
                    activeEmp += std::move(temp);
                    delete temp;
                }
            }
        }

        return activeEmp;
    }
    GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
        GeneratingList<EmployeeWage> activeEmp;

        for (size_t i = 0; i < emp.size(); i++) {
            for (size_t j = 0; j < sal.size(); j++) {
                if (emp[i].id == sal[j].id) {
                    std::unique_ptr<EmployeeWage> temp(new EmployeeWage(emp[i].name, sal[j].salary));
                    temp->rangeValidator();
                    if (!activeEmp.isValidSIN(emp[i].id)) {
                        throw std::string(" ");
                    };
                    activeEmp += std::move(temp);
                }
            }
        }

        return activeEmp;
    }
}