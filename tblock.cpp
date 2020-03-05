#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

#include "xml.h"
#include "tblock.h"

TBlock::TBlock(short number, TTime begin, TTime end) {
	if(number >= 1) {
		this->number = number;
	} else {
		this->number = 1;
	}
	this->begin = begin;
	this->end = end;
}

void TBlock::setNumber(short num) {
	if(num >= 1) {
		this->number = num;
	} else {
		this->number = 1;
	}
}

void TBlock::setBegin(TTime begin) {
	this->begin = begin;
}

void TBlock::setBegin(string timestring) {
	this->begin = TTime(timestring);
}

void TBlock::setEnd(TTime end) {
	this->end = end;
}

void TBlock::setEnd(string timestring) {
	this->end = TTime(timestring);
}

short TBlock::getNumber() {
	return number;
}

TTime TBlock::getBegin() {
	return begin;
}

TTime TBlock::getEnd() {
	return end;
}

bool TBlock::withinRangeOf(TBlock *block, int minutes) {
	if (end.getInSeconds() > block->getBegin().getInSeconds()) {
		return block->withinRangeOf(this, minutes);
	}
	
	int diff = (minutes * 60);
	return (end.getInSeconds() + diff) < block->getBegin().getInSeconds(); // block 2 starts within 'minutes' minutes after block 1 
}

void TBlock::print() {
	cout << begin << " - " << end;
}

istream& operator>>(istream& in, TBlock &obj) {  
	string line;
	string *element;

	do {
		getline(in, line);
		element = XML::extract_elements(line);

		if(element[0] == "BlockNr")
			obj.setNumber(XML::conv_int(element[1]));

		if(element[0] == "Starttime")
			obj.setBegin(element[1]);

		if(element[0] == "Endtime")
			obj.setEnd(element[1]);

	} while(!XML::is_close_tag(XML::peek_line(in)));

	return in;
}