#ifndef TBLOCK_H
#define TBLOCK_H

#include "ttime.h"

class TBlock
{
	private:
		short number; // begins with 1
		TTime begin;
		TTime end;

	public:
		TBlock() {};
		TBlock(short number, TTime begin, TTime end);

		void setNumber(short num);
		void setBegin(TTime begin);
		void setBegin(string timestring);
		void setEnd(TTime end);
		void setEnd(string timestring);

		short getNumber();
		TTime getBegin();
		TTime getEnd();

		void print();

		bool withinRangeOf(TBlock *block, int minutes);

		static bool begins_first(TBlock *block1, TBlock *block2) { 
			return (block1->getBegin().getInSeconds() < block2->getBegin().getInSeconds()); 
		}

		friend istream& operator>>(istream& in, TBlock &obj);
};

#endif // TBLOCK_H