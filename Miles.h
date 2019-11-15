#include <string>

using namespace std;
 #ifndef Miles_H
 #define Miles_H
class Miles{
    //public members
    public:
        Miles();
        Miles(int numMiles, int numDays,int numMonth,int numYear,int endGameDay,int endGameMonth,int endGameYear);
        void setNumMiles(int m);
        void setDate(int numDays,int numMonth,int numYear);
        void setEndDate(int dayEnd,int monthEnd,int yearEnd);
        int getNumMiles();
        int getDay();
        int getMonth();
        int getYear();
        int getEndDay();
        int getEndMonth();
        int getEndYear();
        
    //private members
    private:
       int numberOfDays;
       int month;
       int day;
       int year;
       int endMonth;
       int endDay;
       int endYear;
       int miles;
        
        
};
#endif