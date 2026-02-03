#include "HOTEL.H"
#include <iostream>
#include<string.h>

using namespace std;

//Date class

Date::Date() : month(0), day(0), year(0){}; //default cosntructor

Date::Date(int m, int d, int y) : month(m), day(d), year(y){}; //param constructor

int Date::get_month() const { return month;}

int Date::get_day() const { return day; }

int Date::get_year()const { return year; }

void Date::set_month(int m){
    month = m;
}

void Date::set_day(int d) {
    day = d;
}

void Date::set_year(int y) { 
    year = y;
}

void Date::print_date() const{
    cout << month << " " << day << " " << year << endl;
    
} 


//Information class function

//parametrized constructor for Information
Information::Information(char* fn ,char* ln ,int d, int m, int y){
    strcpy(fname , fn);
    strcpy(lname , ln);
    Date DOB(d,m,y);
}

void Information::print_info() const{
    cout << fname << " " << lname << endl;
    DOB.print_date();
};

Date Information::get_DOB() const{
    return DOB;
}



string Guests::toString(){

    
    return 
}
