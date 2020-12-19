#include <vector>
#include <fstream>
#include <ostream>

#include "employee.h"
#include "roster.h"

const char CHOICE_1 = '1';
const char CHOICE_2 = '2';
const char CHOICE_3 = '3';
const char CHOICE_4 = '4';
const char CHOICE_5 = '5';
const char CHOICE_0 = '0';

const int SIGN_AROUND_NAME_NUMBER = 5;
const int LINE_LENGTH = 20;

const char SIGN_AROUND_NAME = '*';
const char LINE_SIGN = '-';

const int MINIMAL_AGE = 18;
const int MAX_AGE = 150;

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
void updateEmployee();
void searchMenu();
void subMenu();
// additional functions
void printRoster(std::vector<Employee>, std::ostream&);
std::vector<Employee> findEmployee();
std::vector<std::string> splitInputBySpace(std::string&);
std::string jmbgInput();
bool is_number(const std::string&);
void writeFiles();
void readFiles();
roster_it findByJmbg();
std::vector<std::string> employeeInput(const int&);
std::string ageInput();
char choiceInput();
