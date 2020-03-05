#ifndef TTIME_H
#define TTIME_H

#include <string>

class TTime
{
    private:
        int hour;
        int minute;

    public:
        TTime();
        TTime(int hour, int minute);
        TTime(string time);
        void print();
        int getHour();
        int getMinute();  

        long getInSeconds();    

        friend ostream& operator<<(ostream& out, TTime &obj);
};

#endif // TTIME_H
