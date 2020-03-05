#ifndef TPRACTICE_H
#define TPRACTICE_H

#include "tevent.h"
#include "tteacher.h"
#include "tsubject.h"
#include "tblock.h"
#include "troom.h"

class TPractice : public TEvent
{
	private:
		int count;
	public:
		TPractice() : TEvent() {}
	    TPractice(TSubject *subject, int number, TTeacher *teacher, Weekday day, 
	    	TBlock *block, TRoom *room, string semester, int count) :
	    	TEvent(subject, number, teacher, day, block, room, semester),
	    	count(count) {}

	    void setCount(int count);

	    void print();

	    friend istream& operator>>(istream& in, TPractice &obj);
};

#endif // TPRACTICE_H