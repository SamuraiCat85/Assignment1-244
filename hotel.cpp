#include "HOTEL.H"
#include <iostream>
#include<string.h>
#include<string>

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
    cout << month << "/" << day << "/" << year << endl;
    
} 

string Date::DateToString() const{
    string str = (to_string(month)) + "/" + (to_string(day)) + "/" + (to_string(year));

    return str;
}

//Information class function

//default constructor

Information::Information() {
    strcpy(fname , "");
    strcpy(lname , "");
    Date DOB();
} 

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



//Get information memebr variables
Date Information::get_DOB() const{
    return DOB;
}

char* Information::get_fname(){
    return fname;
}

char* Information::get_lname(){
    return lname;
}

//set member variables for Information

void Information::set_DOB(int m, int d, int y){
    DOB.set_month(m);
    DOB.set_day(d);
    DOB.set_year(y);
}

void Information::set_fname(char* fn){
    strcpy(fname , fn);
} 

void Information::set_lname(char* ln){
    strcpy(lname , ln);
}

string Information::InfoToString() const {
    string str = string(fname) + " " + string(lname) + " " + DOB.DateToString();

    return str;

}
//Guests member functions

//default constructor

Guests::Guests(){
    checkIn = Date();
    checkOut = Date();
    //Room number --> if static room number counter < 20 then ?????///////////ASKKKK IN PODDD SESSSIIONN
    roomGuests = new Information[4];
}




//param constructor

Guests::Guests(int m1, int d1, int y1, int m2, int d2, int y2, int rm)
: checkIn(m1, d1, y1), checkOut(m2, d2, y2), 
 roomNumber(rm){
    roomGuests = new  Information[4];
 }


void Guests::AddGuest(const Information& newGuest){
    if(NumGuests < 4){
        roomGuests[NumGuests] = newGuest;
        NumGuests++;
    }
    else{
        cout<< "Could not add more guests. Maximum number of guests reached" << endl;
    }
}

string Guests::toString(){
    string str = "Room number " + to_string(roomNumber) + ": \n";
    for (int i = 0; i < NumGuests; i++){
        str = str + (roomGuests[i].InfoToString()) + "\n";
    }

    str = str + "Check in Date:" + checkIn.DateToString() + "\n";
    str = str + "Check out Date:" + checkOut.DateToString() + "\n";
            
    return str; 
}
