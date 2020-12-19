#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

class Employee {
	private:
		std::string name;
		std::string surname;
		std::string jmbg;
		std::string department;
		int age;
	public:
		Employee();
		Employee(std::string&, std::string&, int&, std::string& jmbg, std::string& department);
		~Employee();
		void setName(std::string);
		void setSurname(std::string);
		void setAge(int);
		void setJmbg(std::string);
		void setDepartment(std::string);
		std::string getName();
		std::string getSurname();
		int getAge();
		std::string getJmbg();
		std::string getDepartment();
};

#endif // _EMPLOYEE_H_ 
