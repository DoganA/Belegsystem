#ifndef TEVENT_H
#define TEVENT_H

#include <vector>
#include <string>
#include "xml.h"
#include "association.h"
#include "tsubject.h"
#include "tperson.h"
#include "tblock.h"
#include "troom.h"

#define MAX_PAUSE_MINS 45

enum Weekday { Mo, Di, Mi, Do, Fr, Sa, So, NoWeekday };

class TEvent : public Association
{
	private:
		TSubject *subject;
		int number;
		TPerson *teacher;
		Weekday day;
		vector<TBlock *> blocks;
		TRoom *room;
		string semester;

		static void printBlockSpan(vector<TBlock *> blockspan);
	public:
		TEvent() : Association() {}
		TEvent(TSubject *subject, int number, TPerson *teacher, Weekday day, 
			TBlock *block, TRoom *room, string semester);

		int getNumber();
		Weekday getWeekday();
		TBlock * getFirstBlock();
		TSubject * getSubject();
		TPerson * getTeacher();
		TRoom * getRoom();
		int getBlockCount();
		string getSemester();

		void setNumber(int number);
		void setWeekday(Weekday day);
		void setWeekday(string day);
		void setTeacher(TPerson *teacher);
		void setSubject(TSubject *subject);
		void setRoom(TRoom *room);
		void setSemester(string semester);

		vector<vector<TBlock *> > getCoherendBlocks();
		void addBlock(TBlock *block);
		vector<TBlock *> getBlocks();

		void printTimeSpan();
		void virtual print();

		static string  stringFromWeekday(Weekday day);
		static Weekday weekdayFromString(string day);
		static string  shortStringFromWeekday(Weekday day);

		friend ostream& operator<<(ostream& out, TEvent &obj);
};

#endif // TEVENT_H 