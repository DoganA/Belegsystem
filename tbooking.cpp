#include <iostream>
#include <cstdio>

using namespace std;

#include "xml.h"
#include "tbooking.h"

void TBooking::print() {
	cout << number << ": " << event->getSubject()->getName() << " (" << event->getSemester() << ") (belegt am " << booking_date << " um " << booking_time << "; Rang " << rating << ")";  
}

void TBooking::setNumber(int number) {
	this->number = number;
}

void TBooking::setDate(string day) {
	this->booking_date = day;
}

void TBooking::setTime(string timestamp) {
	this->booking_time = timestamp;
}

void TBooking::setRating(int rating) {
	this->rating = rating;
}

void TBooking::setEvent(TEvent *event) {
	this->event = event;
}

void TBooking::setStudent(TStudent *student) {
	this->student = student;
}

bool TBooking::is_student(string name) {
	return (this->student->getName() == name);
}

TStudent* TBooking::getStudent() {
	return student;
}

TEvent* TBooking::getEvent() {
	return event;
}

string TBooking::getSubjectName() {
	return event->getSubject()->getName();
}

string TBooking::getTeacherName() {
	return event->getTeacher()->getName();
}

string TBooking::getRoomName() {
	return event->getRoom()->getName();
}




istream& operator>>(istream& in, TBooking &obj) {  
	string line;
	string *element;

	vector<string> keywords;
	keywords.push_back("Event");
	keywords.push_back("Student");

	do {
		getline(in, line);
		element = XML::extract_elements(line);

		if(element[0] == "BookingNr")
			obj.setNumber(XML::conv_int(element[1]));

		if(element[0] == "Date")
			obj.setDate(element[1]);

		if(element[0] == "Time")
			obj.setTime(element[1]);

		if(element[0] == "Rating")
			obj.setRating(XML::conv_int(element[1]));

		if(XML::is_string_in(element[0], keywords))
			obj.push_link(line);

	} while(!XML::is_close_tag(XML::peek_line(in)));

	return in;
}

ostream& operator<<(ostream& out, TBooking &obj) {
	obj.print();
	return out; 
}