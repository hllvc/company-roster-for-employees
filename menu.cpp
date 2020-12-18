#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>

#include "employee.h"
#include "roster.h"
#include "menu.h"

Company company;

void printMainMenu() {
	std::cout << "\t" << std::string(5, '*') << " MAIN MENU " << std::string(5, '*') << "\n\n";
	std::cout << " 1) New Employee\n";
	std::cout << " 2) All Employees\n";
	std::cout << " 3) Delete Employee\n";
	std::cout << "\n 0) Exit\n" << std::endl;
	std::cout << "Choice: ";
}

void newEmployee() {
	std::string name, surname;
	int age;

	std::cout << "Name: ";
	std::cin >> name;
	company.employee.setName(name);
	std::cout << "Surname: ";
	std::cin >> surname;
	company.employee.setSurname(surname);
	std::cout << "Age: ";
	std::cin >> age;
	company.employee.setAge(age);
	company.roster.addToRoster(company.employee);
}

void allEmployees() {
	std::cout << "\t" << std::string(5, '*') << " ALL EMPLOYEES " << std::string(5, '*') << std::endl;
	printRoster(company.roster.getRoster());
}

void printRoster(std::vector<Employee> roster) {
	for (auto it = roster.begin(); it != roster.end(); std::advance(it, 1)) {
		std::cout << std::string(20, '-') << std::endl;
		std::cout << "Name: " << it->getName() << std::endl;
		std::cout << "Surname: " << it->getSurname() << std::endl;
		std::cout << "Age: " << it->getAge() << std::endl;
		std::cout << std::string(20, '-') << std::endl;
	}
}

void deleteEmployee() {
	std::string name;
	std::cout << "Name: ";
	std::cin >> name;
	try {
		company.roster.deleteFromRoster(company.roster.findEmployee(name));
	} catch (int e) {
		if (e == 0)
			std::cout << "No Match!";
	}
}

void findEmployee() {
	std::string input;
	std::vector<std::string> split_input;
	std::cout << "\t" << std::string(5, '*') << " FIND EMPLOYEE " << std::string(5, '*') << "\n\n";
	std::cout << "Find by Name or Surname or both: ";
	std::cin >> input;
	split_input = splitInputBySpace(input);
}

std::vector<std::string> splitInputBySpace(std::string& input) {
	std::istringstream iss(input);
	std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
	return results;
}
