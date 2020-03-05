#ifndef TSCHEDULE_H
#define TSCHEDULE_H

#include <vector>
#include <string>
#include <fstream>

#include "tliste.h"
#include "tbookings.h"
#include "tbooking.h"

#define DAYS 6
#define BLOCKS 8

class TSchedule
{
	private:
		string title;
		TBooking* schedule[BLOCKS][DAYS];
		
		void print_divider(char fillment = ' ');
		void print_head();
	public:
		void print();

		void setStudentsplan(TBookings &bookings, string name);
};

#endif // TSCHEDULE_H