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
			case choice_1:
				newEmployee();
				break;
			case choice_2:
				allEmployees();
				break;
			case choice_3:
				deleteEmployee();
				break;
			case choice_4:
				findEmployeeByNameSurname();
				break;
			case choice_5:
				updateEmployee();
				break;
			case choice_0:
				writeFiles();
				return 0;
			default:
				std::cout << "Wrong input!" << std::endl << "You can either enter 1, 2, 3, 4, 5, or 0!" << std::endl;
		}
	}
}
