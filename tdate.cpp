#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdio.h>

using namespace std;

#include "tdate.h"

TDate::TDate()
{

   time_t rawtime;                    // die fundementale zeit-erithmetik deklarieren
   struct tm * timeinfo;              // die  Zeit-Struktur deklarieren  mit den zeit-variablen

   time (&rawtime);                   // die lokale zeit herausfinden
   timeinfo = localtime (&rawtime);   // lokale zeit ins timeinfo zuweisen

    day   = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year  = timeinfo->tm_year + 1900;
}

TDate::TDate(int day, int month, int year)
{
    this->day   = day;
    this->month = month;
    this->year  = year;
}

TDate::TDate(string date)
{
  struct tm tm;
  strptime(date.c_str(), "%d.%m.%Y", &tm);

  day = tm.tm_mday;
  month = tm.tm_mon + 1;
  year = tm.tm_year + 1900;
}

void TDate::print(){
  cout << setw(2) << setfill('0') << right << day << "." << setw(2) << right 
       << month << "." << setw(2) << right << year << setfill(' ');
}

int TDate::getDay(){
    return day;
}
int TDate::getMonth(){
    return month;
}
int TDate::getYear(){
    return year;
}

ostream& operator<<(ostream& out, TDate &obj) {
  obj.print();
  return out;
}
