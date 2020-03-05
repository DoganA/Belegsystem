#ifndef TTUTOR_H
#define TTUTOR_H

#include "tstudent.h"
#include "tteacher.h"


class TTutor : public TStudent, public TTeacher
{
	private:
		int tutorSemester;
	public:
		TTutor() : TPerson(), TStudent(), TTeacher() {}
		TTutor(string name, int day, int month, int year, int matrNr, int semester, 
			int group, int credits, int persNr, int tutorSemester) :
			TPerson(name, day, month, year),
			TStudent(name, day, month, year, matrNr, semester, group, credits),
			TTeacher(name, day, month, year, persNr),
			tutorSemester(tutorSemester) {}


		void print();
		int getTermsOfTutor();
};

#endif // TTUTOR_H