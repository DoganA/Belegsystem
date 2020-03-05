#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "tstudent.h"

void TStudent::print() {
	cout << TPerson::getName() << " (MatrNr. " << matrNr << ")";
} 

int TStudent::getMatrNr() {
	return matrNr;
}

int TStudent::getSemester() {
	return semester;
}

int TStudent::getGroup() {
	return group;
}

int TStudent::getCredits() {
	return credits;
}
