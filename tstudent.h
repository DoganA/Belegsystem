#ifndef TSTUDENT_H
#define TSTUDENT_H

#include "tperson.h"

class TStudent : public virtual TPerson
{
	private:
		int matrNr;
		int semester;
		int group;
		int credits;

	public:
		TStudent() : TPerson() {}
		TStudent(string name, int day,  int month, int year, 
			int matrNr, int semester, int group, int credits) : 
			TPerson(name, day, month, year), 
			matrNr(matrNr), semester(semester), group(group), credits(credits) {}

		int getMatrNr();
		int getSemester();
		int getGroup();
		int getCredits();

		void print();
};

#endif // TSTUDENT_H