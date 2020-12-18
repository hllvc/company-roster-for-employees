#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

class Employee {
	private:
		std::string name;
		std::string surname;
		int age;
		
	public:
		void setName(std::string);
		void setSurname(std::string);
		void setAge(int);
		std::string getName();
		std::string getSurname();
		int getAge();
};

#endif // _EMPLOYEE_H_ 
