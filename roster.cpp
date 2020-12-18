#include <iterator>
#include <vector>

#include "employee.h"
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

std::vector<Employee> Roster::findEmployee(std::vector<std::string>& split_input) {
	std::vector<Employee> results;
	for (auto it = this->roster.begin(); it != this->roster.end(); std::advance(it, 1)) {
		for (auto it_2 = split_input.begin(); it_2 != split_input.end(); std::advance(it_2, 1)) {
			if (it->getName() == it_2 || it->getSurname() == it_2)
				results.push_back(it);
		}
	}
	// for (auto it = this->roster.begin(); it != this->roster.end(); std::advance(it, 1)) {
	// 	if (it->getName() == input)
	// 		return it;
	// }
	// throw 0;
}

std::vector<Employee> Roster::getRoster() {
	return this->roster;
}
