#include <vector>

#include "employee.h"
#include "roster.h"

struct Company {
	Employee employee;
	Roster roster;
};

// main menu functions
void printMainMenu(), newEmployee(), allEmployees(), deleteEmployee();
// additional functions
void printRoster(std::vector<Employee>);
