/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 5- Feb-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
#include <cmath>
#include "Pair.h"
#include "Collection.h"
#include <string>
namespace sdds {

    template<class T>
    class Set : public Collection<T, 100> {

        const size_t CAPACITY = 100;

    public:

        Set() { ; }

        bool add(const T& item) {

            for (int i = 0; (unsigned)i < this->numOfElements; i++)
            {
                if (item == this->array[i])
                {
                    return false;
                }
            }

            return Collection<T, 100>::add(item);
        }

    };

    template<>
    bool Set<double>::add(const double& item) {

        for (int i = 0; (unsigned)i < this->numOfElements; i++)
        {
            if (std::fabs(item - this->array[i]) <= 0.01)
            {
                return false;

            }
        }
        return Collection<double, 100>::add(item);
    };
}
#endif 