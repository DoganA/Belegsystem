#ifndef TSUBJECT_H
#define TSUBJECT_H

#include "xml.h"
#include "association.h"
#include "tsubjecttype.h"

class TSubject : public Association
{
	private:
		string subject;
		int number;
		short  max_students;
		short term;
		short credits;
		TSubjectType *type;
	
	public:
		TSubject(): Association() {}
		TSubject(string subject, int number, short max, short term, 
				 short credits, TSubjectType *type);

		void setName(string subject);
		void setNumber(int number);
		void setMaxStudents(short max);
		void setTerm(short term);
		void setCredits(short credits);
		void setType(TSubjectType *type);

		string getName();
		int getNumber();
		short getMaxStudents();
		short getTerm();
		short getCredits();
		TSubjectType * getType();

		void print();

		friend istream& operator>>(istream& in, TSubject &obj);
		friend ostream& operator<<(ostream& out, TSubject &obj);
};

#endif // TSUBJECT_H