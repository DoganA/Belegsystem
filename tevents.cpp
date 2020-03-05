#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "tevents.h"

void TEvents::addEvent(TEvent *event) {
	this->events.push_back(event);
}

int TEvents::getEventCount() {
	return events.size();
}

TEvent * TEvents::getEvent(int id) {
	return events[id];
}

void TEvents::print() {
	for(int i = 0; i < events.size(); i++) {
		cout << i+1 << ": ";
		events[i]->print();
		cout << endl;
	}
}