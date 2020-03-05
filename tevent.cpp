#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

#include "tevent.h"

TEvent::TEvent(TSubject *subject, int number, TPerson *teacher, Weekday day, TBlock *block, TRoom *room, string semester) : Association() {
	this->subject = subject;
	this->number = number;
	this->teacher = teacher;
	this->day = day;
	this->room = room;
	this->semester = semester;
	this->blocks.push_back(block);
}

int TEvent::getNumber() {
	return number;
}

Weekday TEvent::getWeekday() {
	return day;
}

TBlock * TEvent::getFirstBlock() {
	return blocks.front();
}

int TEvent::getBlockCount() {
	return blocks.size();
}

TSubject * TEvent::getSubject() {
	return subject;
}

TPerson * TEvent::getTeacher() {
	return teacher;
}

TRoom * TEvent::getRoom() {
	return room;
}

vector<TBlock *> TEvent::getBlocks() {
	return blocks;
}

string TEvent::getSemester() {
	return semester;
}

void TEvent::setNumber(int number) {
	this->number = number;
}

void TEvent::setWeekday(Weekday day) {
	this->day = day;
}

void TEvent::setWeekday(string day) {
	this->day = TEvent::weekdayFromString(day);
}

void TEvent::setTeacher(TPerson *teacher) {
	this->teacher = teacher;
}

void TEvent::setSubject(TSubject *subject) {
	this->subject = subject;
}

void TEvent::setRoom(TRoom *room) {
	this->room = room;
}

void TEvent::setSemester(string semester) {
	this->semester = semester;
}

void TEvent::printTimeSpan() {
	vector<vector<TBlock *> > coherendBlocks = getCoherendBlocks();

	for(int i=0; i < coherendBlocks.size(); i++) {
		if (i > 0) {
			cout << ", ";
		}
		TEvent::printBlockSpan(coherendBlocks[i]);
	}
}

void TEvent::addBlock(TBlock *block) {
	blocks.push_back(block);
	sort(blocks.begin(), blocks.end(), TBlock::begins_first);
}

void TEvent::print() {
	vector<vector<TBlock *> > coherendBlocks = getCoherendBlocks();
	int block_size = coherendBlocks.size();

	for(int i=0; i < block_size; i++) {
		cout << "\t" << setw(12) << left << TEvent::stringFromWeekday(day) + ", ";
		TEvent::printBlockSpan(coherendBlocks[i]);
		cout << " " << setw(20) << left << subject->getName();
		cout << " " << setw(20) << left << teacher->getName();
		cout << " " << setw(12) << left << room->getName();
		
		if (i+1 < block_size) {
			cout << endl;
		}
	}
}

vector<vector<TBlock *> > TEvent::getCoherendBlocks() {
	vector<vector<TBlock *> > coherendBlocks;
	vector<TBlock *> vecTmp;
	TBlock *lastBlock;

	for (int i=0; i < blocks.size(); i++) {
		if (i == 0 || lastBlock->withinRangeOf(blocks[i], MAX_PAUSE_MINS)) {
			coherendBlocks.push_back(vecTmp);
		}

		coherendBlocks.back().push_back(blocks[i]);

		lastBlock = blocks[i];
	}

	return coherendBlocks;
}

// PRIVATE

void TEvent::printBlockSpan(vector<TBlock *> blockspan) {
	TTime begin = blockspan.front()->getBegin();
	TTime end   = blockspan.back()->getEnd();

	cout << begin << " - " << end;
}

string TEvent::stringFromWeekday(Weekday day) {
	switch(day)
	{
	  case Mo: return "Montag";
	  case Di: return "Dienstag";
	  case Mi: return "Mittwoch";
	  case Do: return "Donnerstag";
	  case Fr: return "Freitag";
	  case Sa: return "Samstag";
	  case So: return "Sonntag";
	  default: return "";
	}
}

string TEvent::shortStringFromWeekday(Weekday day) {
	switch(day)
	{
	  case Mo: return "Mo";
	  case Di: return "Di";
	  case Mi: return "Mi";
	  case Do: return "Do";
	  case Fr: return "Fr";
	  case Sa: return "Sa";
	  case So: return "So";
	  default: return "";
	}
}

Weekday TEvent::weekdayFromString(string day) {
	if (day == "Montag"     or (day == "Mo")) { return Mo; }
	if (day == "Dienstag"   or (day == "Di")) { return Di; }
	if (day == "Mittwoch"   or (day == "Mi")) { return Mi; }
	if (day == "Donnerstag" or (day == "Do")) { return Do; }
	if (day == "Freitag"    or (day == "Fr")) { return Fr; }
	if (day == "Samstag"    or (day == "Sa")) { return Sa; }
	if (day == "Sonntag"    or (day == "So")) { return So; }
	return NoWeekday;
}

ostream& operator<<(ostream& out, TEvent &obj) {
	obj.print();
	return out; 
}