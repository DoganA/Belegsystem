#ifndef TBOOKINGS_H
#define TBOOKINGS_H

#include <vector>
#include <string>
#include <fstream>
#include "tliste.h"
#include "tblock.h"
#include "troom.h"
#include "tstudent.h"
#include "tteacher.h"
#include "ttutor.h"
#include "tsubject.h"
#include "tsubjecttype.h"
#include "tlecture.h"
#include "tpractice.h"
#include "association.h"
#include "tbooking.h"

enum ObjectType { Block, Room, Student, Teacher, Tutor, Booking,
				  SubjectType, Subject, Lecture, Practice, Unknown };

class TBookings
{
	private:
		vector<TBlock *> blocks;
		vector<TRoom *> rooms;
		vector<TTeacher *> teachers;
		vector<TStudent *> students;
		vector<TSubject *> subjects;
		vector<TSubjectType *> subjecttypes;
		vector<TEvent *> events;
		TListe<TBooking *> bookings;

		TListe<TBooking *> current_student_search;
		TListe<TBooking *>::Iterator current_student_pos;

		string decodeXml(ifstream& file);
		string run_through_object(string node, ifstream& file);
		ObjectType translate_node(string node_name);

		void associate_event(TEvent &obj);
		void associate_subject(TSubject &obj);
		void associate_booking(TBooking &obj);

		// finder
		TSubjectType* find_subjectType_by_name(string name);
		TSubject* 	  find_subject_by_name(string name);
		TTeacher*	  find_teacher_by_name(string name);
		TStudent*	  find_student_by_name(string name);
		TRoom* 		  find_room_by_name(string name);
		TEvent* 	  find_event_by_name(string name);
		TBlock* 	  find_block_by_number(int number);
		
	public:
		TBookings(string name);

		void print();
		void print_numbered_list_of_students();

		string get_student_name_by_id(int id);

		TBooking * 	  find_first_booking_from_student(string name);
		TBooking *	  find_next_booking_from_student();
};

#endif // TBOOKINGS_H