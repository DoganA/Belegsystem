#include <ctime>
#include <iostream>
#include <stdio.h>

using namespace std;

#include "ttime.h"


TTime::TTime()
{
   time_t rawtime;                    // die fundementale zeit-erithmetik deklarieren
   struct tm * timeinfo;              // die  Zeit-Struktur deklarieren

   time (&rawtime);                   // die lokale zeit herausfinden
   timeinfo = localtime (&rawtime);   // lokale zeit ins timeinfo zuweisen

   hour   =  timeinfo->tm_hour;
   minute =  timeinfo->tm_min;
}

TTime::TTime(int x,int y)
{
    hour    = x;
    minute  = y;
}

TTime::TTime(string timestring)
{
  struct tm tm;
  strptime(timestring.c_str(), "%H:%M", &tm);

  hour = tm.tm_hour;
  minute = tm.tm_min;
}

void TTime::print()
{
    printf("%02d:%02d", getHour(), getMinute());
}

int TTime::getHour()
{
    return hour;
}
int TTime::getMinute()
{
    return minute;
}

long TTime::getInSeconds() {
  return ((hour * 3600) + (minute * 60));
}  

ostream& operator<<(ostream& out, TTime &obj) {
  obj.print();
  return out;
}
