#include <iostream>
#include <cstdio>
#include <regex>

using namespace std;

#include "xml.h"
#include "tbookings.h"

TBookings::TBookings(string name) {
	ifstream file(name);	// file pointer/stream of parameter file
	string line; 			// used as line buffer

	if (file) {				// only continue if file was found
		decodeXml(file);
	} else {				// Let the user know, that file could not be found
		cout << "[ERR] file not found" << endl;
		exit(1);			// exit the program with error code
	}

	file.close();			// close the file stream
}

void TBookings::print() {
	int i;	

	cout << "Belegung Stundenten:" << endl;
	cout << "====================" << endl << endl;

	for(i=0; i < students.size(); i++) {
	 	cout << students[i]->getName() << ":" << endl;
	 	TBooking* bk = find_first_booking_from_student(students[i]->getName());

	 	while (bk) {
	 		cout << " " << *bk << endl;
	 		bk = find_next_booking_from_student();
	 	}

	 	cout << endl;
	}
}

// works in recursion
string TBookings::decodeXml(ifstream& file) {
	string line;			// used as line buffer
	string node;			// the start node
	string current_node;	// the momentary node
	
	getline(file, line);
	node = XML::node_name(line);

	if (XML::is_open_tag(line)) {
		do {
			
			if (node == "Data")
				line = decodeXml(file);
			
			current_node = XML::node_name(line);

			if(XML::is_open_tag(line))
				return run_through_object(current_node, file);

		} while(node != current_node);
	}
	return line;
}

string TBookings::run_through_object(string node, ifstream& file) {
	string line;

	switch(translate_node(node)) {
		case Block: { 
				TBlock *obj = new TBlock;
				file >> *obj; 
				blocks.push_back(obj);
			} break;
		case Room: { 
				TRoom *obj = new TRoom;
				file >> *obj; 
				rooms.push_back(obj);
			} break;
		case Student: { 
				TStudent *obj = new TStudent;
				file >> *obj; 
				students.push_back(obj);
			} break;
		case Teacher: { 
		 		TTeacher *obj = new TTeacher;
		 		file >> *obj; 
		 		teachers.push_back(obj);
		 	} break;
		case Tutor: { 
		 		TTutor *obj = new TTutor;
		 		file >> *obj; 
		 		teachers.push_back(obj);
		 		students.push_back(obj);
		 	} break;
		case SubjectType: { 
		 		TSubjectType *obj = new TSubjectType;
		 		file >> *obj; 
		 		subjecttypes.push_back(obj);
		 	} break;
		case Subject: { 
		 		TSubject *obj = new TSubject;
		 		file >> *obj; 
		 		subjects.push_back(obj);
		 	} break;
		 case Lecture: { 
		 		TLecture *obj = new TLecture;
		 		file >> *obj;
		 		associate_event(*obj);

		 		events.push_back(obj);
		 	} break;
		 case Practice: { 
		 		TPractice *obj = new TPractice;
		 		file >> *obj;
		 		associate_event(*obj);

		 		events.push_back(obj);
		 	} break;
		 case Booking: { 
		 		TBooking *obj = new TBooking;
		 		file >> *obj;
		 		associate_booking(*obj);

		 		bookings.push_back(obj);
		 	} break;
		default:
			while(!XML::is_close_tag(line)) { getline(file, line); }
			return line;
	}

	getline(file, line);
	return line;
}

ObjectType TBookings::translate_node(string node_name) {
	if (node_name == "Block") 		{ return Block; }
	if (node_name == "Room") 		{ return Room; }
	if (node_name == "Student") 	{ return Student; }
	if (node_name == "Teacher") 	{ return Teacher; }
	if (node_name == "Tutor") 		{ return Tutor; }
	if (node_name == "SubjectType") { return SubjectType; }
	if (node_name == "Subject") 	{ return Subject; }
	if (node_name == "Lecture") 	{ return Lecture; }
	if (node_name == "Practice") 	{ return Practice; }
	if (node_name == "Booking") 	{ return Booking; }

	return Unknown; // default case
}

void TBookings::associate_event(TEvent &obj) {
	string link;
	string *element;

	while(obj.has_link()) {
 		link = obj.pop_link();
 		element = XML::extract_elements(link);

 		if(element[0] == "Block") {
 			obj.addBlock(find_block_by_number(XML::conv_int(element[1])));
 		}

 		if(element[0] == "Teacher") {
 			obj.setTeacher(find_teacher_by_name(element[1]));
 		}

 		if(element[0] == "Subject") {
 			obj.setSubject(find_subject_by_name(element[1]));
 		}

 		if(element[0] == "Room") {
 			obj.setRoom(find_room_by_name(element[1]));
 		}
 	}
}

void TBookings::associate_subject(TSubject &obj) {
	string link;
	string *element;

	while(obj.has_link()) {
 		link = obj.pop_link();
 		element = XML::extract_elements(link);

 		if (element[0] == "Type") {
 			obj.setType(find_subjectType_by_name(element[1]));
 		}
 	}
}

void TBookings::associate_booking(TBooking &obj) {
	string link;
	string *element;

	while(obj.has_link()) {
 		link = obj.pop_link();
 		element = XML::extract_elements(link);

 		if (element[0] == "Event") {
 			obj.setEvent(find_event_by_name(element[1]));
 		}

 		if (element[0] == "Student") {
 			TStudent *student = find_student_by_name(element[1]); 
 			obj.setStudent(student);
 		}
 	}
}

TSubjectType* TBookings::find_subjectType_by_name(string name) {
	for (int i=0; i < subjecttypes.size(); i++)
		if (subjecttypes[i]->getSubject() == name)
			return subjecttypes[i];

	return NULL;
}

TSubject* TBookings::find_subject_by_name(string name) {
	for (int i=0; i < subjects.size(); i++)
		if (subjects[i]->getName() == name)
			return subjects[i];

	return NULL;
}

TTeacher* TBookings::find_teacher_by_name(string name) {
	for (int i=0; i < teachers.size(); i++)
		if (teachers[i]->getName() == name)
			return teachers[i];

	return NULL;
}

TStudent* TBookings::find_student_by_name(string name) {
	for (int i=0; i < students.size(); i++)
		if (students[i]->getName() == name)
			return students[i];

	return NULL;
}

TRoom* TBookings::find_room_by_name(string name) {
	for (int i=0; i < rooms.size(); i++)
		if (rooms[i]->getName() == name)
			return rooms[i];

	return NULL;
}

TEvent* TBookings::find_event_by_name(string name) {
	for (int i=0; i < events.size(); i++)
		if (events[i]->getSubject()->getName() == name)
			return events[i];

	return NULL;
}

TBlock* TBookings::find_block_by_number(int number) {
	for (int i=0; i < blocks.size(); i++)
		if (blocks[i]->getNumber() == number)
			return blocks[i];

	return NULL;
}

TBooking* TBookings::find_first_booking_from_student(string name) {
	current_student_search.clear();
	
	TListe<TBooking *>::Iterator iter(bookings);

	while(iter != bookings.end()) {
		// Temporary booking
		TBooking* tmp_bk = bookings.get_element(iter);
		
		if(tmp_bk->is_student(name)) {
			current_student_search.push_back(tmp_bk);
		}

		iter++;
	}

	if (current_student_search.size() > 0) {
		current_student_pos = current_student_search.begin();
		return current_student_search.front();
	}

	return NULL;
}

TBooking* TBookings::find_next_booking_from_student() {
	if (++current_student_pos != current_student_search.end()) {
		return current_student_search.get_element(current_student_pos);
	}
	return NULL;
}

void TBookings::print_numbered_list_of_students() {
	int i;

	for(i = 0; i < students.size(); i++) {
		cout << i+1 << ": " << students[i]->getName() << endl;
	}
}

string TBookings::get_student_name_by_id(int id) {
	if (students[id-1]) {
		return students[id-1]->getName();
	}
	return "";
}