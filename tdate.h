#ifndef TDATE_H
#define TDATE_H

#include <string>

class TDate
{
    private:
        int day;
        int month;
        int year;

    public:
        TDate();
        TDate(string date);
        TDate(int day, int month, int year);
        void print();
        int getDay();
        int getMonth();
        int getYear();

        friend ostream& operator<<(ostream& out, TDate &obj);
};

#endif // TDATE_H
