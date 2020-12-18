#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

class Employee {
	private:
		std::string name, surname;
		int age;
		
	public:
		void setName(std::string), setSurname(std::string), setAge(int);
		std::string getName(), getSurname();
		int getAge();
};

#endif // _EMPLOYEE_H_ 
