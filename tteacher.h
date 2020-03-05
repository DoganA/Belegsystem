#ifndef TTEACHER_H
#define TTEACHER_H

#include "tperson.h"

class TTeacher : public virtual TPerson
{
	private:
		int persNr;
	public:
		TTeacher() : TPerson() {}
		TTeacher(string name, int day, int month, int year, int persNr) :
			TPerson(name, day, month, year), persNr(persNr) {}

		int getPersNr();
};

#endif // TTEACHER_H