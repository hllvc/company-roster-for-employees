#include <iterator>
#include <vector>

#include "employee.h"
#include "roster.h"

void Roster::addToRoster(const Employee& employee) {
	this->roster.push_back(employee);
}

void Roster::deleteFromRoster(roster_it& it) {	
	it = this->roster.erase(it);
}

std::vector<Employee> Roster::findEmployee(std::vector<std::string>& split_input) {
	std::vector<Employee> by_names;
	std::vector<Employee> by_surnames;
	std::vector<Employee> result;
	for (auto it = this->roster.begin(); it != this->roster.end(); std::advance(it, 1)) {
		for (auto it_2 = split_input.begin(); it_2 != split_input.end(); std::advance(it_2, 1)) {
			if (it->getName() == *it_2)
				by_names.push_back(*it);
			if (it->getSurname() == *it_2)
				by_surnames.push_back(*it);
		}
	}
	if (split_input.size() > 1) {
		for (auto it = by_names.begin(); it != by_names.end(); std::advance(it, 1))
			for (auto it_2 = by_surnames.begin(); it_2 != by_surnames.end(); std::advance(it_2, 1))
				if (it->getName() == it_2->getName() && it->getSurname() == it_2->getSurname())
					result.push_back(*it);
		return result;
	} else {
		if (!by_names.empty())
			return by_names;
		else if (!by_surnames.empty())
			return by_surnames;
	}
	throw 0;
	// for (auto it = this->roster.begin(); it != this->roster.end(); std::advance(it, 1)) {
	// 	if (it->getName() == input)
	// 		return it;
	// }
	// throw 0;
}

std::vector<Employee> Roster::getRoster() {
	return this->roster;
}

bool Roster::checkJMBG(std::string& jmbg) {
	for (auto it = this->roster.begin(); it != this->roster.end(); std::advance(it, 1))
		if (it->getJmbg() == jmbg)
			return false;
	return true;
}

roster_it Roster::findEmployee(std::string& jmbg) {
	for (auto it = this->roster.begin(); it != this->roster.end(); std::advance(it, 1))
		if (it->getJmbg() == jmbg)
			return it;
	throw 0;
}
