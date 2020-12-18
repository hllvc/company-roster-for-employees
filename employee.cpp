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

std::string Employee::getName() {
	return this->name;
}

std::string Employee::getSurname() {
	return this->surname;
}

int Employee::getAge() {
	return this->age;
}
