#include <vector>
#include <fstream>
#include <ostream>

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
void findEmployeeByNameSurname();
// additional functions
void printRoster(std::vector<Employee>, std::ostream&);
std::vector<Employee> findEmployee();
std::vector<std::string> splitInputBySpace(std::string&);
std::string jmbgInput();
bool is_number(const std::string&);
void writeFiles();
