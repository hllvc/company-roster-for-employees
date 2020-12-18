#include <vector>

#include "employee.h"
#include "roster.h"

struct Company {
	Employee employee;
	Roster roster;
};

// main menu functions
void printMainMenu();
void newEmployee();
void allEmployees();
void deleteEmployee();
void findEmployee();
// additional functions
void printRoster(std::vector<Employee>);
std::vector<std::string> splitInputBySpace(std::string&);
