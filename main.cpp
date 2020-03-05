#include <iostream>
#include <cstdio>

using namespace std;

#include "tbookings.h"
#include "tschedule.h"

int main()
{
   int selection; 
   bool tried = false;

   TBookings Belegung("data.xml");
   TSchedule Stdplan;

   Belegung.print();
   cout << endl;
   
   cout << "Stundenpläne der Stundenten:" << endl;
   cout << "============================" << endl << endl;

   Belegung.print_numbered_list_of_students();
   cout << "-------------------------------------" << endl;
   cout << "Wählen Sie einen Studenten: ";

    do {
    	if(tried)
   			cout << "Ungültige Eingabe, versuchen Sie es erneut: ";

   		cin >> selection;
   		if(selection == 0) { 
   			cout << "Wird abgebrochen!" << endl;
   			exit(0); 
   		}
   		
   		tried = true;
   } while(Belegung.get_student_name_by_id(selection) == "");

   Stdplan.setStudentsplan(Belegung, Belegung.get_student_name_by_id(selection));
   Stdplan.print();
   //cout << Stdplan << endl;

   return 0;
}
