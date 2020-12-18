#ifndef _ROSTER_H_
#define _ROSTER_H_ 

#include <vector>

#include "employee.h"

typedef std::vector<Employee>::iterator roster_it;

class Roster {
	private:
		std::vector<Employee> roster;
	public:
		void addToRoster(const Employee&); // , deleteFromRoster(Employee&);
		void deleteFromRoster(roster_it);
		roster_it findEmployee(std::string input);
		std::vector<Employee> getRoster();
};

#endif // _ROSTER_H_
