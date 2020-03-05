#ifndef TPERSON_H
#define TPERSON_H

#include "xml.h"
#include "tdate.h"

class TPerson
{
	private:
		string name;
		TDate birthday;

	public:
		TPerson() {}
		TPerson(string name, short day, short month, short year);

		void setName(string name);
		void setBirthday(short day, short month, short year);
		void setBirthday(string date);

		string getName();
		TDate getBirthday();

		void virtual print();
		friend istream& operator>>(istream& in, TPerson &obj); 
		friend ostream& operator<<(ostream& out, TPerson &obj);
};

#endif // TPERSON_H