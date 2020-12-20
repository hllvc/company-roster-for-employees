#include <cstdlib>
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
	std::cout << "\n\t" << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << " MAIN MENU " << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << "\n\n";
	std::cout << " " << CHOICE_1 << ") New Employee\n";
	std::cout << " " << CHOICE_2 << ") All Employees\n";
	std::cout << " " << CHOICE_3 << ") Find Employee\n";
	std::cout << "\n " << CHOICE_C << ") Clear Roster\n";
	std::cout << " " << CHOICE_H << ") Help\n";
	std::cout << "\n " << CHOICE_0 << ") Exit\n" << std::endl;
	std::cout << "Choice: ";
}

void mainMenu() {
	char choice;
	while (true) {
		printMainMenu();
		choice = choiceInput();
		switch (choice) {
			case CHOICE_1:
				newEmployee();
				break;
			case CHOICE_2:
				allEmployees();
				break;
			case CHOICE_3:
				findEmployeeByNameSurname();
				break;
			case CHOICE_C:
				resetAllSettings();
				break;
			case CHOICE_H:
				getHelp();
				break;
			case CHOICE_0:
				writeFiles();
				exit(0);
			default:
				std::cout << "Wrong input!" << std::endl << "You can either enter " << CHOICE_1 << ", " << CHOICE_2 << ", " << CHOICE_3 << ", " << CHOICE_4 << ", " << CHOICE_5 << " or " << CHOICE_0 << "!" << std::endl;
		}
	}
}

void resetAllSettings() {
	std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
	std::cout << "Are you sure to continue? (Y/n): ";
	char choice;
	try {
		choice = yesNoChoice();
	} catch (int e) {
		if (e == 0)
			std::cout << "Some error occured! Try again!" << std::endl;
	}
	if (choice == 'Y') {
		company.roster.clearRoster();
		writeFiles();
	}
	return;
}

char yesNoChoice() {
	char choice;
	while (std::cin >> choice) {
		if (choice == 'Y' || choice == 'n')
			return choice;
		else
			std::cout << "Not and option! Try again: ";
	}
	throw 0;
}

char choiceInput() {
	std::string choice;
	while (std::cin >> choice) {
		if (choice.size() > 1)
			return 'e';
		else return choice.at(0);
	}
	throw 0;
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
	std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
	std::cout << "Name: ";
	std::cin >> s_input;
	input.push_back(s_input);
	std::cout << "Surname: ";
	std::cin >> s_input;
	input.push_back(s_input);
	try {
		std::cout << "Age: ";
		s_input = ageInput();
		input.push_back(s_input);

	} catch (int e) {
		if (e == 0)
			std::cout << "Some error occured. Try again!" << std::endl;
	}
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
	std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
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
					std::cout << "JMBG already exist. Try again: ";
			} else
				std::cout << "JMBG is all digits! Try again: ";
		} else
			std::cout << "JMBG must be 13 numbers! Try again: ";
	}
	throw 0;
}

std::string ageInput() {
	std::string input;
	int age;
	while (std::cin >> input){
		if (is_number(input)) {
			age = std::stoi(input);
			if (age <= 0 || age >= MAX_AGE)
				std::cout << "Please enter your real age: ";
			else if (age < MINIMAL_AGE && age > 0)
				std::cout << "Your are underage! Try again: ";
			else
				return input;
		} else
			std::cout << "Age must be as digit: ";
	}
	throw 0;
}

bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void allEmployees() {
	std::cout << "\n\t" << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << " ALL EMPLOYEES " << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << std::endl;
	std::vector<Employee> roster = company.roster.getRoster();
	if (!roster.empty()) {
		printRoster(roster, std::cout);
		subMenu();
	} else {
		std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
		std::cout << "Roster is empty!" << std::endl;
		return;
	}
	return;
}

void printRoster(std::vector<Employee> roster, std::ostream& output) {
	for (auto it = roster.begin(); it != roster.end(); std::advance(it, 1)) {
		output << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
		output << "Name: " << it->getName() << std::endl;
		output << "Surname: " << it->getSurname() << std::endl;
		output << "Age: " << it->getAge() << std::endl;
		output << "JMBG: " << it->getJmbg() << std::endl;
		output << "Department: " << it->getDepartment() << std::endl;
		output << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
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
		if (e == 0) {
			std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
			std::cout << "No Match!" << std::endl;
		}
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
			std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
			std::cout << "List is empty!" << std::endl;
			return;
		}
	} catch (int e) {
		if (e == 0) {
			std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
			std::cout << "No Match!" << std::endl;
		}
	}
}

void subMenu() {
	char choice;
	while (true) {
		searchMenu();
		choice = choiceInput();
		switch (choice) {
			case CHOICE_1:
				findEmployeeByNameSurname();
				return;
			case CHOICE_2:
				deleteEmployee();
				return;
			case CHOICE_3:
				newEmployee();
				allEmployees();
				return;
			case CHOICE_4:
				updateEmployee();
				return;
			case CHOICE_0:
				return;
			default:
				std::cout << "Wrong input!" << std::endl << "You can either enter " << CHOICE_1 << ", " << CHOICE_2 << ", " << CHOICE_3 << " or " << CHOICE_0 << "!" << std::endl;
		}
		return;
	}
}

void searchMenu() {
	std::cout << "\nOptions:\n\n";
	std::cout << " " << CHOICE_1 << ") Search\n";
	std::cout << " " << CHOICE_2 << ") Delete\n";
	std::cout << " " << CHOICE_3 << ") New\n";
	std::cout << " " << CHOICE_4 << ") Update\n";
	std::cout << "\n " << CHOICE_0 << ") Back\n";
	std::cout << "\nChoice: ";
}

std::vector<Employee> findEmployee() {
	std::string input;
	std::vector<std::string> split_input;
	std::vector<Employee> list;
	std::cout << "\n\t" << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << " FIND EMPLOYEE " << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << "\n\n";
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
	std::cout << "\n\t" << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << " UPDATE EMPLOYEE " << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << "\n\n";
	roster_it it = findByJmbg();
	std::vector<std::string> input = employeeInput(0);
	company.roster.updatePerson(it, input);
}

void writeFiles() {
	std::ofstream file("data");
	std::vector<Employee> roster = company.roster.getRoster();
	printRoster(roster, file);
	file.close();
}

void readFiles() {
	Employee employee;
	std::vector<std::string> split_input;
	std::string line;
	std::ifstream file("data");
	if (file.fail()) {
		std::ofstream file("data");
		getHelp();
		std::cout << "This help is shown this time as it is initial run of programm. For showing help again type character \'" << CHOICE_H << "\' at MAIN MENU! Enyoj." << std::endl;
		std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
	}
	int age;
	while (getline (file, line)) {
		if (line == std::string(LINE_LENGTH, LINE_SIGN))
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
	file.close();
}

void getHelp() {
	std::ifstream file("help");
	std::string line;
	while (getline (file, line))
		std::cout << line << std::endl;
	file.close();
}
