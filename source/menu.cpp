#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>

#include <algorithm>

#include <fstream>

#include "../header/employee.h"
#include "../header/roster.h"
#include "../header/menu.h"

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
		try {
			choice = choiceInput();
		} catch (int& e) {
			if (e == 0)
				std::cout << "Some error occured! Try again!" << std::endl;
		}
		std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
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
				deleteRoster();
				break;
			case CHOICE_H:
				getHelp();
				std::cout << " # " << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
				break;
			case CHOICE_0:
				writeFiles();
				exit(0);
			default:
				std::cout << "Wrong input!" << std::endl << "You can either enter " << CHOICE_1 << ", " << CHOICE_2 << ", " << CHOICE_3 << ", " << CHOICE_C << " for clearing roster, " << CHOICE_H << " for help or " << CHOICE_0 << "!" << std::endl;
		}
	}
}

void deleteRoster() {
	std::cout << "Are you sure to continue? (Y/n): ";
	char choice;
	try {
		choice = yesNoChoice();
	} catch (int& e) {
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
	return;
}

std::string input() {
	std::string input;
	std::cin >> input;
	return input;
}

std::vector<std::string> employeeInput(const int& value) {
	std::string s_input;
	std::vector<std::string> v_input;
	std::cout << "Name: ";
	s_input = input();
	v_input.push_back(s_input);
	std::cout << "Surname: ";
	s_input = input();
	v_input.push_back(s_input);
	std::cin.ignore();
	try {
		std::cout << "Age: ";
		s_input = ageInput(value);
		v_input.push_back(s_input);

	} catch (int& e) {
		if (e == 0)
			std::cout << "Some error occured. Try again!" << std::endl;
	}
	if (value == 1){
		std::cout << "JMBG: ";
		try {
			s_input = jmbgInput();	
			v_input.push_back(s_input);
		} catch (int& e) {
			if (e == 0)
				std::cout << "Some error occured. Try again!" << std::endl;
		}
	}
	std::cout << "Department: ";
	std::cin.ignore();
	std::getline(std::cin, s_input, '\n');
	std::cin.clear();
	std::cin.sync();
	v_input.push_back(s_input);
	std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
	return v_input;
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

std::string ageInput(const int& value) {
	std::string input;
	int age;
	while (std::cin >> input){
		if (is_number(input) && !(input.size() > 3)) {
			age = std::stoi(input);
			if (value == 0 && age == 0)
				return input;
			else if (age <= 0 || age >= MAX_AGE)
				std::cout << "Please enter your real age: ";
			else if (age < MINIMAL_AGE && age > 0)
				std::cout << "Your are underage! Try again: ";
			else
				return input;
		} else
			if (input.empty())
				return input;
			else
				std::cout << "Age must be digit/Can't be huge number";
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
	std::cout << "\n\t" << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << " DELETE EMPLOYEE " << std::string(SIGN_AROUND_NAME_NUMBER, SIGN_AROUND_NAME) << "\n\n";
	roster_it it = findByJmbg();
	company.roster.deleteFromRoster(it);
	return;
}

roster_it findByJmbg() {
	std::string jmbg;
	std::cout << "JMBG: ";
	std::cin >> jmbg;
	roster_it it;
	try {
		it = company.roster.findEmployee(jmbg);
	} catch (int& e) {
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
	} catch (int& e) {
		if (e == 0) {
			std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
			std::cout << "No Match!" << std::endl;
		}
	}
	return;
}

void subMenu() {
	char choice;
	while (true) {
		searchMenu();
		try {
			choice = choiceInput();
		} catch (int& e) {
			if (e == 0)
				std::cout << "Some error occured! Try again!" << std::endl;
		}
		std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
		switch (choice) {
			case CHOICE_1:
				findEmployeeByNameSurname();
				return;
			case CHOICE_2:
				deleteEmployee();
				allEmployees();
				return;
			case CHOICE_3:
				newEmployee();
				allEmployees();
				return;
			case CHOICE_4:
				updateEmployee();
				allEmployees();
				return;
			case CHOICE_0:
				return;
			default:
				std::cout << "Wrong input!" << std::endl << "You can either enter " << CHOICE_1 << ", " << CHOICE_2 << ", " << CHOICE_3 << ", " << CHOICE_4 << " or " << CHOICE_0 << "!" << std::endl;
		}
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
	} catch (int& e) {
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
	std::ofstream file("../data");
	std::vector<Employee> roster = company.roster.getRoster();
	printRoster(roster, file);
	file.close();
}

void readFiles() {
	Employee employee;
	std::vector<std::string> split_input;
	std::string line;
	std::ifstream file("../data");
	if (file.fail()) {
		getHelp();
		std::cout << " |		This help is shown this time as it is initial run of program." << std::endl;
		std::cout << " |		For showing help again type character \'" << CHOICE_H << "\' at MAIN MENU!" << std::endl;
		std::cout << " |		Enyoj." << std::endl;
		std::cout << " |" << std::endl;
		std::cout << " # " << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
		char choice;
			while (true){
				std::cout << "\nEnter 1 for accepting terms, 0 for exit and capital R for reading terms: ";
				try {
					choice = choiceInput();
				} catch (int& e) {
					if (e == 0)
						std::cout << "Some error occured! Try again!" << std::endl;
				}
				if (choice == '1') {
					std::ofstream file("../data");
					file.close();
					return;
				}
				else if (choice == 'R') {
					std::ifstream terms("../terms");
					std::string terms_line;
					std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
					while (std::getline(terms, terms_line))
						std::cout << terms_line << std::endl;
					terms.close();
					std::cout << std::string(LINE_LENGTH, LINE_SIGN) << std::endl;
				} else if (choice == '0')
					exit(0);
			}
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
	std::ifstream file("../help");
	std::string line;
	while (getline (file, line))
		std::cout << line << std::endl;
	file.close();
}
