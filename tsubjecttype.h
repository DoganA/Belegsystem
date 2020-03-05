#ifndef TSUBJECTTYPE_H
#define TSUBJECTTYPE_H

#include "xml.h"

class TSubjectType
{
	private:
		string subject;
		bool required;
		bool aw;
		short fb;

	public:
		TSubjectType() {}
		TSubjectType(string subject, bool required, bool aw, short fb);

		void setSubject(string subject);
		void setRequired(bool required);
		void setAW(bool aw);
		void setFB(short fb);

		string getSubject();
		bool getRequired();
		bool getAW();
		short getFB();

		void print();

		friend istream& operator>>(istream& in, TSubjectType &obj);
};

#endif // TSUBJECTTYPE_H