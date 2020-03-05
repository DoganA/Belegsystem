#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

#include "tperson.h"

TPerson::TPerson(string name, short day, short month, short year){
	this->name = name;
	this->birthday = TDate(day, month, year);
}

void TPerson::setName(string name){
	this->name = name;
}

void TPerson::setBirthday(short day, short month, short year){
	this->birthday = TDate(day, month, year);
}

void TPerson::setBirthday(string date){
	this->birthday = TDate(date);
}

string TPerson::getName(){
	return name;
}

TDate TPerson::getBirthday(){
	return birthday;
}

void TPerson::print(){
	cout << getName() << " (* ";
	birthday.print();
	cout << ")";
}

istream& operator>>(istream& in, TPerson &obj) {  
	string line;
	string *element;

	do {
		getline(in, line);
		element = XML::extract_elements(line);

		if(element[0] == "Name")
			obj.setName(element[1]);

		if(element[0] == "Birthday")
			obj.setBirthday(element[1]);

		// if(element[0] == "Endtime")
		// 	obj.setEnd(element[1]);

	} while(!XML::is_close_tag(XML::peek_line(in)));

	return in;
}

ostream& operator<<(ostream& out, TPerson &obj) {
	obj.print();
	return out;
}