#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>

#include <ios>
#include <limits>

#include <algorithm>

#include <fstream>

#include "employee.h"
#include "roster.h"
#include "menu.h"

Company company;

void printMainMenu() {
	std::cout << "\t" << std::string(5, '*') << " MAIN MENU " << std::string(5, '*') << "\n\n";
	std::cout << " 1) New Employee\n";
	std::cout << " 2) All Employees\n";
	std::cout << " 3) Delete Employee\n";
	std::cout << " 4) Find Employee\n";
	std::cout << "\n 0) Exit\n" << std::endl;
	std::cout << "Choice: ";
}

void newEmployee() {
	std::string name, surname, jmbg, department;
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
	std::cout << "JMBG: ";
	try {
		jmbg = jmbgInput();	
	} catch (int e) {
		if (e == 0)
			std::cout << "Some error occured. Try again!" << std::endl;
	}
	company.employee.setJmbg(jmbg);
	std::cout << "Department: ";
	std::cin >> department;
	company.employee.setDepartment(department);
	company.roster.addToRoster(company.employee);
}

std::string jmbgInput() {
	std::string jmbg;
	while (std::cin >> jmbg) {
		if (jmbg.size() == 13) {
			if (is_number(jmbg)) {
				if (company.roster.checkJMBG(jmbg))
					return jmbg;
				else
					std::cout << "JMBG already exist. Enter new one!" << std::endl;
			} else
				std::cout << "JMBG is all digits!" << std::endl;
		} else
			std::cout << "JMBG must be 13 numbers!" << std::endl;
	}
	throw 0;
}

bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void allEmployees() {
	std::cout << "\t" << std::string(5, '*') << " ALL EMPLOYEES " << std::string(5, '*') << std::endl;
	printRoster(company.roster.getRoster(), std::cout);
}

void printRoster(std::vector<Employee> roster, std::ostream& output) {
	for (auto it = roster.begin(); it != roster.end(); std::advance(it, 1)) {
		output << std::string(20, '-') << std::endl;
		output << "Name: " << it->getName() << std::endl;
		output << "Surname: " << it->getSurname() << std::endl;
		output << "Age: " << it->getAge() << std::endl;
		output << "JMBG: " << it->getJmbg() << std::endl;
		output << "Department: " << it->getDepartment() << std::endl;
		output << std::string(20, '-') << std::endl;
	}
}

void deleteEmployee() {
	std::string jmbg;
	std::cout << "JMBG: ";
	std::cin >> jmbg;
	roster_it it;
	try {
		it = company.roster.findEmployee(jmbg);
	} catch (int e) {
		if (e == 0)
			std::cout << "No Match!" << std::endl;
	}
	company.roster.deleteFromRoster(it);
}

void findEmployeeByNameSurname() {
	std::vector<Employee> list;
	try {
		list = findEmployee();
		printRoster(list, std::cout);
	} catch (int e) {
		if (e == 0)
			std::cout << "No Match!" << std::endl;
	}
}

std::vector<Employee> findEmployee() {
	std::string input;
	std::vector<std::string> split_input;
	std::vector<Employee> list;
	std::cout << "\t" << std::string(5, '*') << " FIND EMPLOYEE " << std::string(5, '*') << "\n\n";
	std::cout << "Find by Name or Surname or both: ";
	std::cin.ignore();
	std::getline(std::cin, input, '\n');
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	std::cin.sync();
	split_input = splitInputBySpace(input);
	try {
		list = company.roster.findEmployees(split_input);
	} catch (int e) {
		if (e == 0)
			throw 0;
	}
	return list;
}

std::vector<std::string> splitInputBySpace(std::string& input) {
	std::istringstream iss(input);
	std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
	return results;
}

void writeFiles() {
	std::ofstream file("roster.dat");
	std::vector<Employee> roster = company.roster.getRoster();
	printRoster(roster, file);
}
