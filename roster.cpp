#include <iterator>
#include <vector>

#include "roster.h"

void Roster::addToRoster(const Employee& employee) {
	this->roster.push_back(employee);
}

void Roster::deleteFromRoster(roster_it it) {
	it = this->roster.erase(it);
	// for (auto it = this->roster.begin(); it != this->roster.end(); std::advance(it, 1)) {
	// 	if (employee.getName() == it->getName())
	// 		it = this->roster.erase(it);
	// }
}

roster_it Roster::findEmployee(std::string input) {
	for (auto it = this->roster.begin(); it != this->roster.end(); std::advance(it, 1)) {
		if (it->getName() == input)
			return it;
	}
	throw 0;
}

std::vector<Employee> Roster::getRoster() {
	return this->roster;
}
