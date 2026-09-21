#include <iostream>

using namespace std;

class Date
{
    int year,month,day;
    bool runnian(int y){
        return (y%4==0&&y%100!=0)||(y%400!=0);
    }
    int realDay(int y,int m){
        int day1[12]={31,28,31,30,31,30,31,31,30,31,30};
        int day2[12]={31,29,31,30,31,30,31,31,30,31,30};
        if(runnian(y))
            return day2[m-1];
        else
            return day1[m-1];
    }

public:

    Date(int myyear=1,int mymonth=1,int myday=1){
        if(mymonth<1||mymonth>12||myyear<1||myday>=realDay(myyear,mymonth)||myday<1){
            cout << "wrong!ÖØÖÃÎª2000-1-1"<<endl;
            year=2000;month=1;day=1;
        }
        else{
            year=myyear;
            month=mymonth;
            day=myday;
        }
    }

    Date operator + (int n){
        Date temp=*this;
        temp.day+=n;
        while(temp.day>=temp.realDay(temp.year,temp.month)){
            temp.day-=realDay(temp.year,temp.month);
            temp.month++;
            if(temp.month>12){
                temp.year++;
                temp.month-=12;
            }
        }
        while(temp.month>12){
            temp.year++;
            temp.month-=12;
        }
        return temp;
    }

    Date& operator ++(){
        this->day++;
        while(day>=realDay(year,month)){
            this->month++;
            this->day-=realDay(year,month);
            if(month>12){
                this->year++;
                this->month-=12;
            }
        }
        return *this;
    }

    Date operator ++(int){
        Date temp=*this;
        this->day++;
        while(day>=realDay(year,month)){
            this->month++;
            this->day-=realDay(year,month);
            if(month>=12){
                this->year++;
                this->month-=12;
            }
        }

        return temp;
    }

    bool operator> (Date& d){
        if(this->year!=d.year) return this->year>d.year;
        else if(this->month!=d.month)   return this->month>d.month;
        else return this->day>d.day;
    }
    void output(){
        cout << "Date:"<<year <<"-"<<month<<"-"<<day<<endl;
    }
};

int main()
{
   Date d1(-1,1,55),d2(2020,1,1),d3(2006,11,14),d4;
   d1.output();
   d4=d2+120000;
   d4.output();
   (d3++).output();
   (++d3).output();
   return 0;
}
