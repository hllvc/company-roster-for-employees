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
