#ifndef TLECTURE_H
#define TLECTURE_H

#include "tevent.h"
#include "tteacher.h"
#include "tsubject.h"
#include "tblock.h"
#include "troom.h"
#include "tdate.h"

class TLecture : public TEvent
{
	private:
		TDate testDate;
	public:
		TLecture() : TEvent() {}
		TLecture(TSubject *subject, int number, TTeacher *teacher, Weekday day, TBlock *block,
			TRoom *room, string semester, TDate testDate) :
			TEvent(subject, number, teacher, day, block, room, semester),
			testDate(testDate) {}

		void setTestDate(string date);

		void print();

		friend istream& operator>>(istream& in, TLecture &obj);
};

#endif // TLECTURE_H