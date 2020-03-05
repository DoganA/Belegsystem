#include <iostream>
#include <iomanip>
#include <cstdio>
#include <regex>

using namespace std;

#include "tschedule.h"


void TSchedule::print() {
	int i, j;

	cout << "Stundenplan von " + title << endl;

	print_head();

	for(i = 0; i < BLOCKS; i++) {
		cout << "|     |";
		for(j = 0; j < DAYS; j++) {
			string name = (schedule[i][j]) ? schedule[i][j]->getSubjectName() : "";
			cout << " " << setw(16) << left << name << right << " |";
		}
		cout << endl;


		cout << "|  " << i+1 << "  |";
		for(j = 0; j < DAYS; j++) {
			string name = (schedule[i][j]) ? schedule[i][j]->getTeacherName() : "";
			cout << " " << setw(16) << left << name << right << " |";
		}
		cout << endl;

		cout << "|     |";
		for(j = 0; j < DAYS; j++) {
			string name = (schedule[i][j]) ? schedule[i][j]->getRoomName() : "";
			cout << " " << setw(16) << left << name << right << " |";
		}
		cout << endl;

		print_divider('-');
	}

}

void TSchedule::setStudentsplan(TBookings &bookings, string name) {
	// save name as attribute title
	title = name;

	int i;
	TEvent *ev;
	vector<TBlock *> blocks;

	// grab first booking for a student (n and 1/2 loop)
	TBooking *bk = bookings.find_first_booking_from_student(name);


	while(bk) {
		// temporarly save the event, to lower vector lookups
		ev = bk->getEvent();
		blocks = ev->getBlocks();

		// save each block thats inside an event
		for (i = 0; i < blocks.size(); i++) {
			schedule[blocks[i]->getNumber()][ev->getWeekday()] = bk;
		}


		bk = bookings.find_next_booking_from_student();
	}
}

void TSchedule::print_divider(char fillment) {
	int i;
	cout << "|" << setw(6) << setfill(fillment) << "|";
		for(i = 0; i < DAYS; i++) {
			cout << setw(19) << "|";
		}
	cout << setfill(' ') << endl;
}

void TSchedule::print_head() {
	int i;
	print_divider('-');

	cout << "|" << setw(6) << "|";
		for(i = 0; i < DAYS; i++) {
			cout << setw(10) << TEvent::shortStringFromWeekday((Weekday)i) << setw(9) << "|";
		}
	cout << endl;

	print_divider('-');
}
