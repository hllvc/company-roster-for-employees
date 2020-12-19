#include <iostream>
#include <string>
#include "employee.h"

void Employee::setName(std::string name) {
	this->name = name;
}

void Employee::setSurname(std::string surname) {
	this->surname = surname;
}

void Employee::setAge(int age) {
	this->age = age;
}

void Employee::setJmbg(std::string jmbg) {
	this->jmbg = jmbg;
}

void Employee::setDepartment(std::string department) {
	this->department = department;
}

std::string Employee::getName() {
	return this->name;
}

std::string Employee::getSurname() {
	return this->surname;
}

int Employee::getAge() {
	return this->age;
}

std::string Employee::getJmbg() {
	return this->jmbg;
}

std::string Employee::getDepartment() {
	return this->department;
}
