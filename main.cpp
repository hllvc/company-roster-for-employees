#include <iostream>
#include <ostream>
#include <string>

// #include <limits>
// #include <ios>

#include "employee.h"
#include "roster.h"
#include "menu.h"

int main() {
	readFiles();
	char choice;
	while (true) {
		printMainMenu();
		choice = choiceInput();
		// std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (choice) {
			case CHOICE_1:
				newEmployee();
				break;
			case CHOICE_2:
				allEmployees();
				break;
			case CHOICE_3:
				deleteEmployee();
				break;
			case CHOICE_4:
				findEmployeeByNameSurname();
				break;
			case CHOICE_5:
				updateEmployee();
				break;
			case CHOICE_H:
				getHelp();
				break;
			case CHOICE_0:
				writeFiles();
				return 0;
			default:
				std::cout << "Wrong input!" << std::endl << "You can either enter " << CHOICE_1 << ", " << CHOICE_2 << ", " << CHOICE_3 << ", " << CHOICE_4 << ", " << CHOICE_5 << " or " << CHOICE_0 << "!" << std::endl;
		}
	}
}
