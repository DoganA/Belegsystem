#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

#include "tsubjecttype.h"

TSubjectType::TSubjectType(string subject, bool required, bool aw, short fb) {
	this->subject = subject;
	this->required = required;
	this->aw = aw;
	this->fb = fb;
}

void TSubjectType::setSubject(string subject) {
	this->subject = subject;
}

void TSubjectType::setRequired(bool required) {
	this->required = required;
}

void TSubjectType::setAW(bool aw) {
	this->aw = aw;
}

void TSubjectType::setFB(short fb) {
	this->fb = fb;
}

string TSubjectType::getSubject() {
	return subject;
}

bool TSubjectType::getRequired() {
	return required;
}

bool TSubjectType::getAW() {
	return aw;
}

short TSubjectType::getFB() {
	return fb;
}

void TSubjectType::print() {
	cout << "Fach " << getSubject() << " (FB " << getFB() << ")";
}

istream& operator>>(istream& in, TSubjectType &obj) {  
	string line;
	string *element;

	do {
		getline(in, line);
		element = XML::extract_elements(line);

		if(element[0] == "Name")
			obj.setSubject(element[1]);

		if(element[0] == "RequiredSubject")
			obj.setRequired(XML::conv_bool(element[1]));

		if(element[0] == "AWSubject")
			obj.setAW(XML::conv_bool(element[1]));

		if(element[0] == "FacultyNr")
			obj.setFB(XML::conv_int(element[1]));

	} while(!XML::is_close_tag(XML::peek_line(in)));

	return in;
}
