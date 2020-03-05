#ifndef TEVENTS_H
#define TEVENTS_H

#include "tevent.h"

class TEvents
{
	private:
		vector<TEvent *> events;
	public:
		void addEvent(TEvent *event);
		int getEventCount();
		TEvent * getEvent(int id);

		void print();
};

#endif // TEVENTS_H 