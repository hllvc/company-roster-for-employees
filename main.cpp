#include <iostream>
#include <ostream>
#include <string>

// #include <limits>
// #include <ios>

#include "employee.h"
#include "roster.h"
#include "menu.h"

int main() {
	int choice;
	while (true) {
		printMainMenu();
		std::cin >> choice;
		// std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (choice) {
			case 1:
				newEmployee();
				break;
			case 2:
				allEmployees();
				break;
			case 3:
				deleteEmployee();
				break;
			case 4:
				findEmployee();
				break;
			case 0:
				return 0;
			default:
				std::cout << "Wrong input!" << std::endl;
		}
	}
}
