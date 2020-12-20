#ifndef _MENU_H_
#define _MENU_H_

#include <vector>
#include <fstream>

#include "employee.h"
#include "roster.h"

const char CHOICE_1 = '1';
const char CHOICE_2 = '2';
const char CHOICE_3 = '3';
const char CHOICE_4 = '4';
const char CHOICE_5 = '5';

const char CHOICE_H = 'h';
const char CHOICE_C = 'C';

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
void mainMenu();
void newEmployee();
void allEmployees();
void deleteEmployee();
void findEmployeeByNameSurname();
void updateEmployee();
void searchMenu();
void subMenu();
void getHelp();
void deleteRoster();
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
std::string ageInput(const int&);
char choiceInput();
char yesNoChoice();
std::string input();

#endif // _MENU_H_
