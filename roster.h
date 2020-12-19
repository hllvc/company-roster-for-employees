#ifndef _ROSTER_H_
#define _ROSTER_H_ 

#include <string>
#include <vector>

#include "employee.h"

typedef std::vector<Employee>::iterator roster_it;

class Roster {
	private:
		std::vector<Employee> roster;
	public:
		void addToRoster(const Employee&); // , deleteFromRoster(Employee&);
		void deleteFromRoster(roster_it&);
		void updatePerson(roster_it&, std::string, std::string, int, std::string);
		std::vector<Employee> findEmployees(std::vector<std::string>&);
		roster_it findEmployee(std::string&);
		std::vector<Employee> getRoster();
		bool checkJMBG(std::string&);
		roster_it getLast();
};

#endif // _ROSTER_H_
