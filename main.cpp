#include <iostream>
#include <string>

// #include <limits>
// #include <ios>

#include "employee.h"
#include "roster.h"
#include "menu.h"

int main() {
	printMainMenu();
	int choice;
	while (true) {
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
			case 0:
				return 0;
			default:
				std::cout << "Wrong input!";
		}
	}
}
