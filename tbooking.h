#ifndef TBOOKING_H
#define TBOOKING_H

#include <vector>
#include <string>
#include <fstream>
#include "association.h"
#include "tevent.h"
#include "tstudent.h"
#include "tdate.h"
#include "ttime.h"

class TBooking : public Association
{
	private:
		int number;
		TEvent *event;
		TStudent *student;
		TDate booking_date;
		TTime booking_time;
		int rating;

	public:
		void print();

		void setNumber(int number);
		void setDate(string day);
		void setTime(string timestamp);
		void setRating(int rating);
		void setEvent(TEvent *event);
		void setStudent(TStudent *student);

		bool is_student(string name);

		TStudent* getStudent();
		TEvent* getEvent();

		string getSubjectName();
		string getTeacherName();
		string getRoomName();

		friend istream& operator>>(istream& in, TBooking &obj);
		friend ostream& operator<<(ostream& out, TBooking &obj);
};

#endif // TBOOKING_H