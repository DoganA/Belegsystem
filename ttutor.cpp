#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "ttutor.h"

int TTutor::getTermsOfTutor() {
	return tutorSemester;
}

void TTutor::print() {
	cout << TPerson::getName() << " (MatrNr. " << TStudent::getMatrNr() 
		 << "; PersNr. " << TTeacher::getPersNr() << ")";
}