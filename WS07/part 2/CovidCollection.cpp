/*
Name: Aditya Dharmesh Patel
Student ID: 143595205
email: adpatel31@myseneca.ca
Section: NCC
Date: 20- Mar-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "CovidCollection.h"

namespace sdds {
	std::string& CovidCollection::trim(std::string& token) {
		while (token.length() > 0 && token[0] == ' ')
			token.erase(0, 1);
		while (token.length() > 0 && token[token.length() - 1] == ' ')
			token.erase(token.length() - 1, 1);
		return token;
	}
	CovidCollection::CovidCollection(std::string filename) {
		std::ifstream file(filename);
		if (!file)
			{
				throw "Invalid filename!";
			}

		while (file) {

			Covid n_Covid;
			std::string tmp;
			std::getline(file, tmp);

			if (file) {
				trim(n_Covid.country = tmp.substr(0, 25));
				trim(n_Covid.city = tmp.substr(25, 25));
				trim(n_Covid.variant = tmp.substr(50, 25));
				try {
					n_Covid.year = std::stoi(tmp.substr(75, 5)) < 0 ? " " : tmp.substr(75, 5);
				}
				catch (...) {
					n_Covid.year = '0';
				}
				n_Covid.numberOfCases = std::stoi(tmp.substr(80, 5));
				n_Covid.m_deaths = std::stoi(tmp.substr(85));
				this->covid.push_back(n_Covid);
			}


		}
		file.close();
			
	};
		

	void CovidCollection::display(std::ostream& out) const {
		std::for_each(covid.begin(), covid.end(), [&out](const Covid& covid) {
			out << covid << std::endl;
			});
		auto totalCases = std::accumulate(covid.begin(), covid.end(), 0u, [](const size_t& res, const Covid& theCovid) {
			return res + theCovid.numberOfCases; 
			});
		auto totalDeaths = std::accumulate(covid.begin(), covid.end(), 0u, [](const size_t& res, const Covid& theCovid) {
			return res + theCovid.m_deaths;
			});
		
		for (int i = 0; i < 88; i++)
			out << "-";
		 out << std::endl;

		out <<"|"<< std::right << std::fixed << std::setw(79) << "Total Cases Around the World: " << std::right << std::setw(6) << totalCases << " |" << std::endl;;
		out <<"|"<< std::right << std::fixed << std::setw(79) << "Total Deaths Around the World: " << std::right << std::setw(6) << totalDeaths << " |" << std::endl;;

	}

	void CovidCollection::sort(std::string str) {
		if (str == "country") {
			std::sort(covid.begin(), covid.end(), [](const Covid& c1, const Covid& c2) {
				return c1.country < c2.country;
				});
		}
		else if (str == "variant") {
			std::sort(covid.begin(), covid.end(), [](const Covid& c1, const Covid& c2) {
				return c1.variant < c2.variant;
				});
		}
		else if (str == "cases") {
			std::sort(covid.begin(), covid.end(), [](const Covid& c1, const Covid& c2) {
				return c1.numberOfCases < c2.numberOfCases;
				});
		}
		else if (str == "deaths") {
			std::sort(covid.begin(), covid.end(), [](const Covid& c1, const Covid& c2) {
				return c1.m_deaths < c2.m_deaths;
				});
		}
	}

	void CovidCollection::cleanList() {
		
		std::transform(covid.begin(), covid.end(), covid.begin(), [](Covid c) {
			if (c.variant == "[None]")
				c.variant = "";
			return c;
			});
	}

	bool CovidCollection::inCollection(std::string str) const {
		auto valid = std::find_if(covid.begin(), covid.end(), [&str](const Covid& c) {
			return c.variant == str;
			});
		return valid != covid.end();
	}

	std::list<Covid> CovidCollection::getListForCountry(std::string str) const {
		auto count = std::count_if(covid.begin(), covid.end(), [&str](const Covid& c) {
			return c.country == str;
			});
		
		std::list<Covid>listed(count);
		std::copy_if(covid.begin(), covid.end(), listed.begin(), [&str](const Covid& c) {
			return c.country == str;
			});

		return listed;

	}

	std::list<Covid> CovidCollection::getListForVariant(std::string str) const {
		auto count = count_if(covid.begin(), covid.end(), [&str](const Covid& co) {
			return co.variant == str;
			});

		std::list<Covid>listed(count);
		std::copy_if(covid.begin(), covid.end(), listed.begin(), [&str](const Covid& co) {
			return co.variant == str;
			});
		
		return listed;
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| " << std::left << std::setw(21) << theCovid.country;
		out << " | " << std::left << std::setw(15) << theCovid.city;
		out << " | " << std::left << std::setw(20) << theCovid.variant;
		out << " | " << std::right << std::setw(7) << theCovid.year;
		out << "| " << std::right << std::setw(4) << theCovid.numberOfCases;
		out << " | " << std::right << std::setw(3) << theCovid.m_deaths << " |";

		return out;
	}

}
