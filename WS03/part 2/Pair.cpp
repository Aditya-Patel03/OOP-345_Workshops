/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 5- Feb-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//#include "Collection.h"
#include "Pair.h"
using namespace std;
namespace sdds {

    bool Pair::haveSameKey(const Pair& P, const Pair& N) {
        bool res = false;
        if (P.m_key == N.m_key) {
            res = true;
        }
        return res;
    }

    std::ostream& Pair::display(std::ostream& ostr) const {
        ostr.width(20);
        ostr.setf(ios::right);
        ostr << getKey();
        ostr.setf(ios::left);
        ostr << ": " << getValue();
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Pair& P) {
        return P.display(ostr);
    }
}