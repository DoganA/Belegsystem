#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "tpractice.h"

void TPractice::print() {
	TEvent::print();
	cout << "Anz. Uebungen: " << count;
}

istream& operator>>(istream& in, TPractice &obj) {  
	string line;
	string *element;

	vector<string> keywords;
	keywords.push_back("Teacher");
	keywords.push_back("Block");
	keywords.push_back("Room");
	keywords.push_back("Subject");

	do {
		getline(in, line);
		element = XML::extract_elements(line);

		if(element[0] == "EventNr")
			obj.setNumber(XML::conv_int(element[1]));

		if(element[0] == "Weekday")
			obj.setWeekday(element[1]);

		if(XML::is_string_in(element[0], keywords))
			obj.push_link(line);

		if(element[0] == "PracticeCount")
			obj.setCount(XML::conv_int(element[1]));

		if(element[0] == "Term")
			obj.setSemester(element[1]);

	} while(!XML::is_close_tag(XML::peek_line(in)));

	return in;
}

void TPractice::setCount(int count) {
	this->count = count;
}