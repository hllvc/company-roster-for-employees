#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "employee.h"
#include "roster.h"
#include "menu.h"

Company company;

void printMainMenu() {
	std::cout << "\t" << std::string(5, '*') << " MAIN MENU " << std::string(5, '*') << "\n\n";
	std::cout << " 1) New Employee\n";
	std::cout << " 2) All Employees\n";
	std::cout << " 3) Delete Employee\n";
	std::cout << "\n 0) Exit" << std::endl;
}

void newEmployee() {
	std::string name, surname;
	int age;

	std::cout << "Name: ";
	std::cin >> name;
	company.employee.setName(name);
	std::cout << "Surname: ";
	std::cin >> name;
	company.employee.setSurname(surname);
	std::cout << "Age: ";
	std::cin >> age;
	company.employee.setAge(age);
	company.roster.addToRoster(company.employee);
}

void allEmployees() {	
		printRoster(company.roster.getRoster());
}

void printRoster(std::vector<Employee> roster) {
	for (auto it = roster.begin(); it != roster.end(); std::advance(it, 1))
		std::cout << it->getAge();
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
