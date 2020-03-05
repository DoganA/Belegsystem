#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

#include "tsubject.h"

TSubject::TSubject(string subject, int number, short max, short term, 
				   short credits, TSubjectType *type): Association() {
	this->subject = subject;
	this->number = number;
	this->max_students = max;
	this->term = term;
	this->credits = credits;
	this->type = type;
}


void TSubject::setName(string subject) {
	this->subject = subject;
}

void TSubject::setNumber(int number) {
	this->number = number;
}

void TSubject::setMaxStudents(short max) {
	this->max_students = max;
}

void TSubject::setTerm(short term) {
	this->term = term;
}

void TSubject::setCredits(short credits) {
	this->credits = credits;
}

void TSubject::setType(TSubjectType *type) {
	this->type = type;
}

string TSubject::getName() {
	return subject;
}

int TSubject::getNumber() {
	return number;
}

short TSubject::getMaxStudents() {
	return max_students;
}

short TSubject::getTerm() {
	return term;
}

short TSubject::getCredits() {
	return credits;
}

TSubjectType * TSubject::getType() {
	return type;
}

void TSubject::print() {
	cout << getName() << " (Nr. " << getNumber() << ")";
}

istream& operator>>(istream& in, TSubject &obj) {  
	string line;
	string *element;

	do {
		getline(in, line);
		element = XML::extract_elements(line);

		if(element[0] == "Name")
			obj.setName(element[1]);

		if(element[0] == "SubjectNr")
			obj.setNumber(XML::conv_int(element[1]));

		if(element[0] == "MaxStudents")
			obj.setMaxStudents(XML::conv_int(element[1]));

		if(element[0] == "Term")
			obj.setTerm(XML::conv_int(element[1]));

	} while(!XML::is_close_tag(XML::peek_line(in)));

	return in;
}

ostream& operator<<(ostream& out, TSubject &obj) {
	obj.print();
	return out; 
}