#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

class Employee {
	private:
		std::string name;
		std::string surname;
		std::string jmbg;
		int age;
		
	public:
		void setName(std::string);
		void setSurname(std::string);
		void setAge(int);
		void setJmbg(std::string);
		std::string getName();
		std::string getSurname();
		int getAge();
		std::string getJmbg();
};

#endif // _EMPLOYEE_H_ 
