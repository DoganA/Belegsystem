#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "xml.h"
#include "troom.h"

TRoom::TRoom(string name, string building, short seats)
{
	this->name = name;
	this->building = building;
	this->seats = seats;
}

void TRoom::setName(string name) {
	this->name = name;
}

void TRoom::setBuilding(string building){
	this->building = building;
}

void TRoom::setSeats(short seats){
	this->seats = seats;
}

string TRoom::getName(){
	return name;
}

string TRoom::getBuilding(){
	return building;
}

short TRoom::getSeats(){
	return seats;
}


void TRoom::print(){
	cout << "Raum " << getName() << " (" << getBuilding() << ")";
}

istream& operator>>(istream& in, TRoom &obj) {  
	string line;
	string *element;

	do {
		getline(in, line);
		element = XML::extract_elements(line);

		if(element[0] == "Name")
			obj.setName(element[1]);

		if(element[0] == "Building")
			obj.setBuilding(element[1]);

		if(element[0] == "Seats")
			obj.setSeats(XML::conv_int(element[1]));

	} while(!XML::is_close_tag(XML::peek_line(in)));

	return in;
}