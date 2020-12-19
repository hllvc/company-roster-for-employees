#include <cstdio>
#include <iostream>
#include <iterator>
#include <ostream>
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
	std::cout << " 5) Update Employee\n";
	std::cout << "\n 0) Exit\n" << std::endl;
	std::cout << "Choice: ";
}

void newEmployee() {
	// std::string name, surname, jmbg, department;
	int age;
	// std::cout << "Name: ";
	// std::cin >> name;
	// std::cout << "Surname: ";
	// std::cin >> surname;
	// std::cout << "Age: ";
	// std::cin >> age;
	// std::cout << "JMBG: ";
	// try {
	// 	jmbg = jmbgInput();	
	// } catch (int e) {
	// 	if (e == 0)
	// 		std::cout << "Some error occured. Try again!" << std::endl;
	// }
	// std::cout << "Department: ";
	// std::cin >> department;
	std::vector<std::string> input = employeeInput(1);
	age = std::stoi(input.at(2));
	company.employee = Employee(input.at(0), input.at(1), age, input.at(3), input.at(4));
	company.roster.addToRoster(company.employee);
}

std::vector<std::string> employeeInput(const int& value) {
	std::string s_input;
	std::vector<std::string> input;
	std::cout << "Name: ";
	std::cin >> s_input;
	input.push_back(s_input);
	std::cout << "Surname: ";
	std::cin >> s_input;
	input.push_back(s_input);
	std::cout << "Age: ";
	s_input = ageInput();
	input.push_back(s_input);
	if (value == 1){
		std::cout << "JMBG: ";
		try {
			s_input = jmbgInput();	
			input.push_back(s_input);
		} catch (int e) {
			if (e == 0)
				std::cout << "Some error occured. Try again!" << std::endl;
		}
	}
	std::cout << "Department: ";
	std::cin.ignore();
	std::getline(std::cin, s_input, '\n');
	std::cin.clear();
	std::cin.sync();
	// std::cin >> s_input;
	input.push_back(s_input);
	return input;
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

std::string ageInput() {
	int age;
	while (std::cin >> age){
		if (age <= 0 || age >= 150)
			std::cout << "Please enter your real age!" << std::endl;
		else if (age < 18 && age > 0)
			std::cout << "Your are underage!" <<	std::endl;
		else
			return std::to_string(age);
	}
	throw 0;
}

bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void allEmployees() {
	std::cout << "\t" << std::string(5, '*') << " ALL EMPLOYEES " << std::string(5, '*') << std::endl;
	std::vector<Employee> roster = company.roster.getRoster();
	if (!roster.empty()) {
		printRoster(roster, std::cout);
		subMenu();
	} else {
		std::cout << "Roster is empty!" << std::endl;
		return;
	}
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
	roster_it it = findByJmbg();
	company.roster.deleteFromRoster(it);
}

roster_it findByJmbg() {
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
	return it;
}

void findEmployeeByNameSurname() {
	std::vector<Employee> list;
	try {
		list = findEmployee();
		if (!list.empty()) {
			printRoster(list, std::cout);
			subMenu();
		} else {
			std::cout << "List is empty!" << std::endl;
			return;
		}
		} catch (int e) {
		if (e == 0)
			std::cout << "No Match!" << std::endl;
	}
}

void subMenu() {
	int choice;
	while (true) {
		searchMenu();
		std::cin >> choice;
		switch (choice) {
			case 1:
				deleteEmployee();
				break;
			case 2:
				updateEmployee();
				break;
			case 3:
				newEmployee();
			case 0:
				return;
			default:
				std::cout << "Wrong input!" << std::endl;
		}
		return;
	}
}

void searchMenu() {
	std::cout << " 1) Delete\n";
	std::cout << " 2) Update\n";
	std::cout << " 3) New\n";
	std::cout << "\n 0) Back\n";
	std::cout << "\n Choice: ";
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

void updateEmployee() {
	std::cout << "\t" << std::string(5, '*') << " UPDATE EMPLOYEE " << std::string(5, '*') << "\n\n";
	roster_it it = findByJmbg();
	std::vector<std::string> input = employeeInput(0);
	company.roster.updatePerson(it, input);
}

void writeFiles() {
	std::ofstream file("roster.dat");
	std::vector<Employee> roster = company.roster.getRoster();
	printRoster(roster, file);
}

void readFiles() {
	Employee employee;
	std::vector<std::string> split_input;
	std::string line;
	std::ifstream file("roster.dat");
	int age;
	while (getline (file, line)) {
		if (line == std::string(20, '-'))
			continue;
		split_input = splitInputBySpace(line);	
		if (split_input.at(0) == "Name:")
			employee.setName(split_input.at(1));
		else if (split_input.at(0) == "Surname:")
			employee.setSurname(split_input.at(1));
		else if (split_input.at(0) == "Age:") {
			age = stoi(split_input.at(1));
			employee.setAge(age);
		} else if (split_input.at(0) == "JMBG:")
			employee.setJmbg(split_input.at(1));
		else if (split_input.at(0) == "Department:") {
			for (auto it = split_input.begin() + 2; it != split_input.end(); std::advance(it, 1))
				split_input.at(1) += " " + *it;
			employee.setDepartment(split_input.at(1));
			company.roster.addToRoster(employee);
		}
	}
}
